//
// Created by nikosint on 09.05.23.
//

#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {

  setWindowTitle("VKratse");
  setEnabled(false);

  tabWidget = new QTabWidget(this);

  chatsWidget = new QWidget(this);
  tabWidget->addTab(chatsWidget, "Chats");

  settingsWidget = new QWidget(this);
  tabWidget->addTab(settingsWidget, "Settings");

  authorizationWidget = new AuthorizationDialog(this);
  authorizationWidget->show();
}

MainWindow::~MainWindow() = default;