//
// Created by nikosint on 10.05.23.
//

#include "server.h"

VKratseServer::VKratseServer(QObject *parent) : QTcpServer(parent) {}

void VKratseServer::incomingConnection(qintptr socketDescriptor) {
  auto *worker = new VKratseWorker(this);
  if (!worker->setSocketDescriptor(socketDescriptor)) {
    worker->deleteLater();
    return;
  }
  connect(worker, &VKratseWorker::disconnectedFromClient, this, [this, worker] { userDisconnected(worker); });
  connect(worker, &VKratseWorker::error, this, [this, worker] { userError(worker); });
  connect(worker, &VKratseWorker::jsonReceived, this, [this, worker](auto && PH1) { jsonReceived(worker, std::forward<decltype(PH1)>(PH1)); });
  connect(worker, &VKratseWorker::logMessage, this, &VKratseServer::logMessage);
  workers.append(worker);
  emit logMessage(QStringLiteral("New client connected"));
}

void VKratseServer::stopServer() {
  for (auto *worker : workers) {
    worker->disconnectFromClient();
  }
  close();
}

void VKratseServer::logMessage(const QString &msg) {
  std::cout << (QDate::currentDate().toString("dd.MM.yyyy") + " " + QTime::currentTime().toString() + ": " + msg).toStdString()
            << std::endl;
}

void VKratseServer::jsonReceived(VKratseWorker *from, const QJsonObject &json) {
  if (!from) {
    return;
  }
  logMessage(QLatin1String("JSON received ") + QString::fromUtf8(QJsonDocument(json).toJson()));
  const QJsonValue typeVal = json.value(QLatin1String("type"));
  QJsonObject message;
  QString username, passwordHashed, name, surname, to, text, datetime;
  bool userExists = false, authorizationSuccessful = false;
  if (typeVal.isNull() || typeVal.isUndefined() || typeVal.isArray()) {
    return;
  }
  if (from->getUsername().isEmpty()) {
    switch (typeVal.toInt()) {
      case ClientMessageType::Register:
        username = json.value("username").toString();
        if (username.isEmpty() || username.isNull()) {
          return;
        }
        passwordHashed = json.value("password").toString();
        if (passwordHashed.isEmpty() || passwordHashed.isNull()) {
          return;
        }
        name = json.value("name").toString();
        if (name.isEmpty() || name.isNull()) {
          return;
        }
        surname = json.value("surname").toString();
        if (surname.isEmpty() || surname.isNull()) {
          return;
        }
        //check if user exists in db //todo
        if (userExists) {
          message[QStringLiteral("type")] = ServerMessageType::UserExists;
        } else {
          //add user in db //todo
          message[QStringLiteral("type")] = ServerMessageType::RegistrationSuccessful;
        }
        sendJson(from, message); //reply with an answer
        break;
      case ClientMessageType::LogIn:
        username = json.value("username").toString();
        if (username.isEmpty() || username.isNull()) {
          return;
        }
        passwordHashed = json.value("password").toString();
        if (passwordHashed.isEmpty() || passwordHashed.isNull()) {
          return;
        }
        //check if user exists //todo
        if (!userExists) {
          message[QStringLiteral("type")] = ServerMessageType::NoSuchUser;
        } else {
          //check in db if the password for the user is correct //todo
          if (authorizationSuccessful) {
            //get users name and surname in db //todo
            message[QStringLiteral("name")] = name;
            message[QStringLiteral("surname")] = surname;
            message[QStringLiteral("type")] = ServerMessageType::AuthorizationSuccessful;
          } else {
            message[QStringLiteral("type")] = ServerMessageType::AuthorizationFailed;
          }
        }
        sendJson(from, message); //reply with an answer
        break;
      default:
        logMessage(QLatin1String("JSON incorrect"));
    }
  } else {
    switch (typeVal.toInt()) {
      case ClientMessageType::CheckUser:
        // check in db //todo
        if (userExists) {
          message[QStringLiteral("type")] = ServerMessageType::UserExists;
        } else {
          message[QStringLiteral("type")] = ServerMessageType::NoSuchUser;
        }
        sendJson(from, message); //reply with an answer
        break;
      case ClientMessageType::LogOut:
        userDisconnected(from);
        break;
      case ClientMessageType::SendMessage:
        username = json.value("username").toString();
        if (username.isEmpty() || username.isNull() || username != from->getUsername()) {
          return;
        }
        to = json.value("to").toString();
        if (to.isEmpty() || to.isNull()) {
          return;
        }
        text = json.value("text").toString();
        if (text.isEmpty() || text.isNull()) {
          return;
        }
        datetime = json.value("datetime").toString();
        if (datetime.isEmpty() || datetime.isNull()) {
          return;
        }
        //save message in db //todo
        if (username != to) { // do not send message back if user wrote the message to himself
          for (auto *worker : workers) { // check if recipient is online (maybe on several devices)
            if (worker->getUsername() == to) {
              sendJson(worker, json);
            }
          }
        }
        break;
      default:
        logMessage(QLatin1String("JSON incorrect"));
    }
  }

}

void VKratseServer::userDisconnected(VKratseWorker *user) {
  workers.removeAll(user);
  logMessage(QLatin1String("User ") + user->getUsername() + QLatin1String(" disconnected"));
  user->deleteLater(); // todo
}

void VKratseServer::userError(VKratseWorker *user) {
  if (!user) {
    return;
  }
  logMessage(QLatin1String("Error from ") + user->getUsername());
}

void VKratseServer::sendJson(VKratseWorker *to, const QJsonObject &json) {
  if (!to) {
    return;
  }
  to->sendJson(json);
}
