//
// Created by nikosint on 09.05.23.
//

#ifndef VKRATSECLIENT_AUTHORIZATION_DIALOG_H
#define VKRATSECLIENT_AUTHORIZATION_DIALOG_H

#include "registration_dialog.h"
#include "user.h"

class AuthorizationDialog : public QDialog {
  Q_OBJECT

protected:
  QGridLayout *layout;
  QLabel *vkratseLabel;
  QLineEdit *loginLineEdit, *passwordLineEdit;
  QPushButton *registerButton, *logInButton;
  RegistrationDialog *registrationDialog;
  QWidget *MainWindow;
  VKratseUser *user;

public:
  explicit AuthorizationDialog(QWidget* parent = nullptr, VKratseUser* user = nullptr);
  ~AuthorizationDialog() override;

signals:
  void logInSuccessful();

private slots:
  void refresh() const;
  void logIn();
  void reg() const;
};

#endif //VKRATSECLIENT_AUTHORIZATION_DIALOG_H
