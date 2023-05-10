//
// Created by nikosint on 10.05.23.
//

#include <worker.h>

VKratseWorker::VKratseWorker(QObject *parent) : QObject(parent), socket(new QTcpSocket(this)) {
  connect(socket, &QTcpSocket::readyRead, this, &VKratseWorker::receiveJson);
  connect(socket, &QTcpSocket::disconnected, this, &VKratseWorker::disconnectedFromClient);
  connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &VKratseWorker::error);
}

VKratseWorker::~VKratseWorker() = default;

bool VKratseWorker::setSocketDescriptor(qintptr socketDescriptor) {
  return socket->setSocketDescriptor(socketDescriptor);
}

QString VKratseWorker::getUsername() const {
  return username;
}

void VKratseWorker::setUsername(const QString &string) {
  username = string;
}

void VKratseWorker::sendJson(const QJsonObject &json) {
  const QByteArray jsonData = QJsonDocument(json).toJson(QJsonDocument::Compact);
  emit logMessage("Sending to " + username + " - " + QString::fromUtf8(jsonData));
  QDataStream socketStream(socket);
  socketStream.setVersion(QDataStream::Qt_5_15);
  socketStream << jsonData;
}

void VKratseWorker::disconnectFromClient() {
  socket->disconnectFromHost();
}

void VKratseWorker::receiveJson() {
  QByteArray jsonData;
  QDataStream socketStream(socket);
  socketStream.setVersion(QDataStream::Qt_5_15);
  while (true) {
    socketStream.startTransaction();
    socketStream >> jsonData;
    if (socketStream.commitTransaction()) {
      QJsonParseError parseError{};
      const QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &parseError);
      if (parseError.error == QJsonParseError::NoError) {
        if (jsonDoc.isObject())
                emit jsonReceived(jsonDoc.object());
        else
                emit logMessage("Invalid message: " + QString::fromUtf8(jsonData));
      } else {
        emit logMessage("Invalid message: " + QString::fromUtf8(jsonData));
      }
    } else {
      break;
    }
  }
}
