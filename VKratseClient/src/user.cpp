//
// Created by nikosint on 10.05.23.
//

#include "user.h"

#include <utility>

VKratseUser::VKratseUser() {
  login = name = surname = QString();
}

VKratseUser::VKratseUser(QString login, QString name, QString surname)
  : login(std::move(login)),
    name(std::move(name)),
    surname(std::move(surname)) {}

VKratseUser::~VKratseUser() = default;

QString VKratseUser::getLogin() const {
  return login;
}

QString VKratseUser::getName() const {
  return name;
}

QString VKratseUser::getSurname() const {
  return surname;
}

QString VKratseUser::getNameSurname() const {
  return name + " " + surname;
}

void VKratseUser::setLogin(QString string) {
  this->login = std::move(string);
}

void VKratseUser::setName(QString string) {
  this->name = std::move(string);
}

void VKratseUser::setSurname(QString string) {
  this->surname = std::move(string);
}

bool VKratseUser::isValid() const {
  if (name.isEmpty() || surname.isEmpty() || login.isEmpty()) {
    return false;
  }
  return true;
}
