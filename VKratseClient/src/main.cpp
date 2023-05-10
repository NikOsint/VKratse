#include <QApplication>

#include "client.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  VKratseClient client{};
  client.showMaximized();
  return QApplication::exec();
}
