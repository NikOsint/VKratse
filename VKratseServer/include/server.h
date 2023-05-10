//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSESERVER_SERVER_H
#define VKRATSESERVER_SERVER_H

#include <iostream>

#include <QTcpServer>
#include <QTime>
#include <QDate>

#include "worker.h"

class VKratseServer : public QTcpServer {
  Q_OBJECT
  Q_DISABLE_COPY(VKratseServer)

public:
  explicit VKratseServer(QObject *parent = nullptr);
  ~VKratseServer() override;

protected:
  void incomingConnection(qintptr socketDescriptor) override;

private slots:
  void logMessage(const QString &msg);
  void jsonReceived(VKratseWorker *from, const QJsonObject &json);
  void userDisconnected(VKratseWorker *user);
  void userError(VKratseWorker *user);

private:
  void sendJson(VKratseWorker *to, const QJsonObject &json);
  QVector<VKratseWorker*> workers;
};

#endif //VKRATSESERVER_SERVER_H
