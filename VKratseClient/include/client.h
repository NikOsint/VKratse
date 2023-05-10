//
// Created by nikosint on 09.05.23.
//

#ifndef VKRATSECLIENT_CLIENT_H
#define VKRATSECLIENT_CLIENT_H

#include <QTabWidget>
#include <QTcpSocket>
#include <QHostAddress>

#include "authorization_dialog.h"
#include "settings_widget.h"
#include "chats_widget.h"

class VKratseClient : public QWidget {
  Q_OBJECT

protected:
  QTabWidget *tabWidget;
  QGridLayout *layout;
  AuthorizationDialog *authorizationDialog;
  ChatsWidget *chatsWidget;
  SettingsWidget *settingsWidget;
  VKratseUser *user;
  Chats *chats;
  QTcpSocket *socket;

public:
  explicit VKratseClient(QWidget* parent = nullptr);
  ~VKratseClient() override;

  void connectToServer(const QHostAddress &address, quint16 port) const;

//public slots:

};

#endif //VKRATSECLIENT_CLIENT_H
