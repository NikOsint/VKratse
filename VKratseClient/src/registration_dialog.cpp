//
// Created by nikosint on 09.05.23.
//

#include "registration_dialog.h"

RegistrationDialog::RegistrationDialog(QWidget* parent) : QDialog(parent) {

  setWindowTitle("VKratse Registration");

  layout = new QGridLayout(this);
  layout->setSizeConstraint(QLayout::SetFixedSize);
  this->setLayout(layout);

  registrationLabel = new QLabel(this);
  registrationLabel->setText("Please, introduce yourself");
  registrationLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(registrationLabel, 0, 0, 1, 2);

  nameLabel = new QLabel(this);
  nameLabel->setText("Name");
  layout->addWidget(nameLabel, 1, 0, 1, 1);

  nameLineEdit = new QLineEdit(this);
  layout->addWidget(nameLineEdit, 1, 1, 1, 1);

  surnameLabel = new QLabel(this);
  surnameLabel->setText("Surname");
  layout->addWidget(surnameLabel, 2, 0, 1, 1);

  surnameLineEdit = new QLineEdit(this);
  layout->addWidget(surnameLineEdit, 2, 1, 1, 1);

  loginLabel = new QLabel(this);
  loginLabel->setText("Login");
  layout->addWidget(loginLabel, 3, 0, 1, 1);

  loginLineEdit = new QLineEdit(this);
  layout->addWidget(loginLineEdit, 3, 1, 1, 1);

  passwordLabel = new QLabel(this);
  passwordLabel->setText("Password");
  layout->addWidget(passwordLabel, 4, 0, 1, 1);

  passwordLineEdit = new QLineEdit(this);
  layout->addWidget(passwordLineEdit, 4, 1, 1, 1);

  cancelButton = new QPushButton(this);
  cancelButton->setText("Cancel");
  layout->addWidget(cancelButton, 5, 0, 1, 1);

  registerButton = new QPushButton(this);
  registerButton->setText("Register");
  registerButton->setEnabled(false);
  layout->addWidget(registerButton, 5, 1, 1, 1);

  connect(registerButton, SIGNAL(pressed()), this, SLOT(reg()));
  connect(cancelButton, SIGNAL(pressed()), this, SLOT(cancel()));
  connect(loginLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
  connect(passwordLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
  connect(nameLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
  connect(surnameLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
}

RegistrationDialog::~RegistrationDialog() = default;

void RegistrationDialog::refresh() const {
  if (loginLineEdit->text().isEmpty() || passwordLineEdit->text().isEmpty() ||
      nameLineEdit->text().isEmpty() || surnameLineEdit->text().isEmpty()) {
    registerButton->setEnabled(false);
  } else {
    registerButton->setEnabled(true);
  }
}

void RegistrationDialog::cancel() {
  close();
}

void RegistrationDialog::reg() const {
  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development");
}
