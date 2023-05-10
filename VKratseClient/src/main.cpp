#include <iostream>

#include <QApplication>

#include "client.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  VKratseClient client{};
  if (argc != 3) {
    std::cout << "Incorrect use of VKratseClient.\nUse: \"[VKratseClient Binary Path] [Server IP Address] [Server Port Number]\"\n";
    return 1;
  }
  QHostAddress ip{QString(argv[1])};
  if (ip.isNull()) {
    std::cout << "Invalid IP Address.\nUse: \"[VKratseClient Binary Path] [Server IP Address] [Server Port Number]\"\n";
    return 1;
  }
  int port = std::stoi(std::string(argv[2]));
  if (port <= 0) {
    std::cout << "Invalid Port.\nUse: \"[VKratseClient Binary Path] [Server IP Address] [Server Port Number]\"\n";
    return 1;
  }
  client.connectToServer(ip, port);
  client.showMaximized();
  return QApplication::exec();
}
