//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSECLIENT_CHATS_WIDGET_H
#define VKRATSECLIENT_CHATS_WIDGET_H

#include <QFrame>
#include <QTime>
#include <QDate>

#include "new_chat_dialog.h"

class ChatsWidget : public QWidget {
  Q_OBJECT

protected:
  QGridLayout *layout, *chatsLayout, *messagesLayout;
  QTableWidget *chatsTableWidget, *messagesTableWidget;
  QPushButton *newChatButton, *sendMessageButton;
  QFrame *chatsFrame, *messagesFrame;
  QLineEdit *newMessageLineEdit;
  NewChatDialog *newChatDialog;
  Chats *chats;
  VKratseUser *user;

public:
  explicit ChatsWidget(QWidget* parent = nullptr, Chats *chats = nullptr, VKratseUser *user = nullptr);
  ~ChatsWidget() override;

private slots:
  void refreshMessages() const;
  void refresh() const;
  void sendMessage() const;
  void newChat() const;

private:
  void renderChat(const QString &chat) const;
};

#endif //VKRATSECLIENT_CHATS_WIDGET_H
