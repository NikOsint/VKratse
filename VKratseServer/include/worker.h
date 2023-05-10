//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSESERVER_WORKER_H
#define VKRATSESERVER_WORKER_H

#include <QTcpSocket>
#include <QJsonParseError>
#include <QDataStream>
#include <QJsonObject>

#include "message_type.h"

class VKratseWorker : public QObject
{
  Q_OBJECT
  Q_DISABLE_COPY(VKratseWorker)

public:
  explicit VKratseWorker(QObject *parent = nullptr);
  ~VKratseWorker() override;

  virtual bool setSocketDescriptor(qintptr socketDescriptor);
  QString getUsername() const;
  void setUsername(const QString &username);
  void sendJson(const QJsonObject &json);

signals:
  void jsonReceived(const QJsonObject &json);
  void disconnectedFromClient();
  void error();
  void logMessage(const QString &message);

public slots:
  void disconnectFromClient();

private slots:
  void receiveJson();

private:
  QTcpSocket *socket;
  QString username;
};

#endif //VKRATSESERVER_WORKER_H
