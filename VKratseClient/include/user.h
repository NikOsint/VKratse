//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSECLIENT_USER_H
#define VKRATSECLIENT_USER_H

#include <QString>

class VKratseUser {
public:
  explicit VKratseUser();
  VKratseUser(QString login, QString name, QString surname);
  ~VKratseUser();

  QString getLogin() const;
  QString getName() const;
  QString getSurname() const;
  QString getNameSurname() const;

  void setLogin(QString string);
  void setName(QString string);
  void setSurname(QString string);

  bool isValid() const;

private:
  QString login, name, surname;
};

#endif //VKRATSECLIENT_USER_H
