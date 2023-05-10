//
// Created by nikosint on 09.05.23.
//

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QWidget(parent) {

  setWindowTitle("VKratse");
  setEnabled(false);

  layout = new QGridLayout(this);
  this->setLayout(layout);

  tabWidget = new QTabWidget(this);
  layout->addWidget(tabWidget);

  chatsWidget = new ChatsWidget(this);
  tabWidget->addTab(chatsWidget, "Chats");

  authorizationDialog = new AuthorizationDialog(this);

  settingsWidget = new SettingsWidget(this, authorizationDialog);
  tabWidget->addTab(settingsWidget, "Settings");

  authorizationDialog->show();
}

MainWindow::~MainWindow() = default;
