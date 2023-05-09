//
// Created by nikosint on 09.05.23.
//

#ifndef VKRATSECLIENT_REGISTRATION_DIALOG_H
#define VKRATSECLIENT_REGISTRATION_DIALOG_H

#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class RegistrationDialog : public QDialog {
Q_OBJECT

protected:
  QGridLayout *layout;
  QLabel *registrationLabel, *loginLabel, *passwordLabel, *nameLabel, *surnameLabel;
  QLineEdit *loginLineEdit, *passwordLineEdit, *nameLineEdit, *surnameLineEdit;
  QPushButton *registerButton, *cancelButton;

public:
  explicit RegistrationDialog(QWidget* parent = nullptr);
  ~RegistrationDialog() override;

public slots:
  void refresh() const;
  void reg() const;
  void cancel();
};

#endif //VKRATSECLIENT_REGISTRATION_DIALOG_H
