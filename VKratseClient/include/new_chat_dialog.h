//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSECLIENT_NEW_CHAT_DIALOG_H
#define VKRATSECLIENT_NEW_CHAT_DIALOG_H

#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QMap>
#include <QVector>

#include "user.h"

typedef QVector<QStringList> Chat;
typedef QMap<QString, Chat> Chats;

class NewChatDialog : public QDialog {
  Q_OBJECT

protected:
  QGridLayout *layout;
  QLabel *newChatLabel;
  QLineEdit *newChatLineEdit;
  QPushButton *createChatButton, *cancelButton;
  QTableWidget *chatsTableWidget;
  Chats *chats;

public:
  explicit NewChatDialog(QWidget* parent = nullptr, QTableWidget* chatsTableWidget = nullptr, Chats* chats = nullptr);
  ~NewChatDialog() override;

private slots:
  void refresh() const;
  void createChat();
  void cancel();
};

#endif //VKRATSECLIENT_NEW_CHAT_DIALOG_H
