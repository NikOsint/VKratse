//
// Created by nikosint on 10.05.23.
//

#include "user.h"

#include <utility>

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
