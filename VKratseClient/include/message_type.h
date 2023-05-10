//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSECLIENT_MESSAGE_TYPE_H
#define VKRATSECLIENT_MESSAGE_TYPE_H

enum ServerMessageType {
  AuthorizationSuccessful,
  AuthorizationFailed,
  RegistrationSuccessful,
  NewMessage, // ServerMessageType::NewMessage = ClientMessageType::SendMessage = 3
  UserExists,
  NoSuchUser
};

enum ClientMessageType {
  LogIn,
  LogOut,
  Register,
  SendMessage,
  CheckUser
};

#endif //VKRATSECLIENT_MESSAGE_TYPE_H
