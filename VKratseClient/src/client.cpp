//
// Created by nikosint on 09.05.23.
//

#include "mainwindow.h"

VKratseClient::VKratseClient(QWidget* parent) : QWidget(parent) {

  user = new VKratseUser();

  setWindowTitle("VKratse");
  setEnabled(false);

  layout = new QGridLayout(this);
  this->setLayout(layout);

  tabWidget = new QTabWidget(this);
  layout->addWidget(tabWidget);

  chatsWidget = new ChatsWidget(this);
  tabWidget->addTab(chatsWidget, "Chats");

  authorizationDialog = new AuthorizationDialog(this, user);
  authorizationDialog->show();

  settingsWidget = new SettingsWidget(this, authorizationDialog, user);
  tabWidget->addTab(settingsWidget, "Settings");
}

VKratseClient::~VKratseClient() {
  delete user;
}
