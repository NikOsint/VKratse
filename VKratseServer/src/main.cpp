#include <QCoreApplication>

#include "server.h"

int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);
  VKratseServer server{};
  int port;
  if (argc != 2) {
    std::cout << "Incorrect use of VKratseServer.\nUse: \"[VKratseServer Binary Path] [Port Number]\"\n";
    return 1;
  }
  port = std::stoi(std::string(argv[1]));
  if (!server.listen(QHostAddress::Any, port)) {
    std::cout << "ERROR: Unable to start the server on port " << port << std::endl;
    return 1;
  }
  return QCoreApplication::exec();
}
