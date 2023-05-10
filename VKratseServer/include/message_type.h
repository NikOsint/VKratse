//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSESERVER_MESSAGE_TYPE_H
#define VKRATSESERVER_MESSAGE_TYPE_H

enum ServerMessageType {
  AuthorizationSuccessful,
  AuthorizationFailed,
  RegistrationSuccessful,
  NewMessage, // ServerMessageType::NewMessage = ClientMessageType::SendMessage
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

#endif //VKRATSESERVER_MESSAGE_TYPE_H
