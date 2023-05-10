//
// Created by nikosint on 10.05.23.
//

#include "new_chat_dialog.h"

NewChatDialog::NewChatDialog(QWidget* parent, QTableWidget* chatsTableWidget, Chats* chats): QDialog(parent) {

  this->chatsTableWidget = chatsTableWidget;
  this->chats = chats;

  setWindowTitle("New Chat");

  layout = new QGridLayout(this);
  layout->setSizeConstraint(QLayout::SetFixedSize);
  this->setLayout(layout);

  newChatLabel = new QLabel(this);
  newChatLabel->setText("Who would you like to chat with?");
  newChatLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(newChatLabel, 0, 0, 1, 2);

  newChatLineEdit = new QLineEdit(this);
  newChatLineEdit->setPlaceholderText("Type username...");
  layout->addWidget(newChatLineEdit, 1, 0, 1, 2);

  cancelButton = new QPushButton(this);
  cancelButton->setText("Cancel");
  layout->addWidget(cancelButton, 2, 0, 1, 1);

  createChatButton = new QPushButton(this);
  createChatButton->setText("Create Chat");
  createChatButton->setEnabled(false);
  layout->addWidget(createChatButton, 2, 1, 1, 1);

  connect(createChatButton, SIGNAL(pressed()), this, SLOT(createChat()));
  connect(cancelButton, SIGNAL(pressed()), this, SLOT(cancel()));
  connect(newChatLineEdit, SIGNAL(textEdited(QString)), this, SLOT(refresh()));
}

NewChatDialog::~NewChatDialog() = default;

void NewChatDialog::refresh() const {
  if (newChatLineEdit->text().isEmpty()) {
    createChatButton->setEnabled(false);
  } else {
    createChatButton->setEnabled(true);
  }
}

void NewChatDialog::createChat() {
  QString newChat = newChatLineEdit->text();
  int chatCount = chatsTableWidget->rowCount();
  for (int i = 0; i < chatCount; ++i) {
    if (chatsTableWidget->item(i, 0)->text() == newChat) {
      QMessageBox::information(nullptr, "Chat Already Exists", "You already have chat with " + newChat);
      return;
    }
  }
  chatsTableWidget->setRowCount(chatCount + 1);
  chatsTableWidget->setItem(chatCount, 0, new QTableWidgetItem(newChat));
  chatsTableWidget->item(chatCount, 0)->setBackgroundColor(QColor(166, 220, 237));
  chatsTableWidget->resizeColumnToContents(0);
  chats->operator[](newChat) = Chat();
  newChatLineEdit->clear();
  close();
//  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void NewChatDialog::cancel() {
  close();
}
