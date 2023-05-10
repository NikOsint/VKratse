//
// Created by nikosint on 09.05.23.
//

#ifndef VKRATSECLIENT_CLIENT_H
#define VKRATSECLIENT_CLIENT_H

#include <QTabWidget>

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

public:
  explicit VKratseClient(QWidget* parent = nullptr);
  ~VKratseClient() override;

public slots:

};

#endif //VKRATSECLIENT_CLIENT_H
