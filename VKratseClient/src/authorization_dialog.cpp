//
// Created by nikosint on 09.05.23.
//

#include "authorization_dialog.h"

AuthorizationDialog::AuthorizationDialog(QWidget* parent) : QDialog(parent), MainWindow(parent) {

  setWindowTitle("VKratse");

  layout = new QGridLayout(this);
  layout->setSizeConstraint(QLayout::SetFixedSize);
  this->setLayout(layout);

  vkratseLabel = new QLabel(this);
  vkratseLabel->setText("Hi! It's VKratse Messenger");
  vkratseLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(vkratseLabel, 0, 0, 1, 2);

  loginLineEdit = new QLineEdit(this);
  loginLineEdit->setPlaceholderText("Login");
  layout->addWidget(loginLineEdit, 1, 0, 1, 2);

  passwordLineEdit = new QLineEdit(this);
  passwordLineEdit->setPlaceholderText("Password");
  layout->addWidget(passwordLineEdit, 2, 0, 1, 2);

  registerButton = new QPushButton(this);
  registerButton->setText("Register");
  layout->addWidget(registerButton, 3, 0, 1, 1);

  logInButton = new QPushButton(this);
  logInButton->setText("Log In");
  logInButton->setEnabled(false);
  layout->addWidget(logInButton, 3, 1, 1, 1);

  registrationDialog = new RegistrationDialog(this);

  connect(registerButton, SIGNAL(pressed()), this, SLOT(reg()));
  connect(logInButton, SIGNAL(pressed()), this, SLOT(logIn()));
  connect(loginLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
  connect(passwordLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
}

AuthorizationDialog::~AuthorizationDialog() = default;

void AuthorizationDialog::refresh() const {
  if (loginLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty()) {
    logInButton->setEnabled(false);
  } else {
    logInButton->setEnabled(true);
  }
}

void AuthorizationDialog::logIn() {
  loginLineEdit->clear();
  passwordLineEdit->clear();
  hide();
  if (MainWindow) {
    MainWindow->setEnabled(true);
  }
}

void AuthorizationDialog::reg() const {
  registrationDialog->show();
}
