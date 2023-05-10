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
//  QWidget *mainWindow;

public:
  explicit ChatsWidget(QWidget* parent = nullptr);
  ~ChatsWidget() override;

public slots:
  void refresh() const;
  void sendMessage() const;
  void newChat() const;
};

#endif //VKRATSECLIENT_CHATS_WIDGET_H
