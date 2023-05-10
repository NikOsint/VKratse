//
// Created by nikosint on 10.05.23.
//

#include "chats_widget.h"

ChatsWidget::ChatsWidget(QWidget* parent, Chats *chats, VKratseUser *user) : QWidget(parent) {

  this->chats = chats;
  this->user = user;

  this->layout = new QGridLayout(this);
  this->setLayout(layout);

  chatsFrame = new QFrame(this);
  chatsFrame->setFrameShape(QFrame::Shape::Panel);
  chatsFrame->setFrameShadow(QFrame::Shadow::Plain);
  chatsFrame->setLineWidth(1);
  chatsFrame->setMidLineWidth(1);
  chatsFrame->setMaximumWidth(300);
  layout->addWidget(chatsFrame, 0, 0);
  chatsLayout = new QGridLayout(chatsFrame);
  chatsFrame->setLayout(chatsLayout);
  chatsTableWidget = new QTableWidget(this);
  chatsTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  chatsTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  chatsTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  chatsTableWidget->setColumnCount(1);
  chatsTableWidget->setHorizontalHeaderLabels({"Chats"});
  chatsLayout->addWidget(chatsTableWidget, 0, 0);
  newChatButton = new QPushButton(this);
  newChatButton->setText("New Chat");
  chatsLayout->addWidget(newChatButton, 1, 0);

  messagesFrame = new QFrame(this);
  messagesFrame->setFrameShape(QFrame::Shape::Panel);
  messagesFrame->setFrameShadow(QFrame::Shadow::Plain);
  messagesFrame->setLineWidth(1);
  messagesFrame->setMidLineWidth(1);
  messagesFrame->setMinimumWidth(300);
  layout->addWidget(messagesFrame, 0, 1);
  messagesLayout = new QGridLayout(messagesFrame);
  messagesFrame->setLayout(messagesLayout);
  messagesTableWidget = new QTableWidget(this);
  messagesTableWidget->setSelectionMode(QAbstractItemView::NoSelection);
  messagesTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
  messagesTableWidget->setColumnCount(3);
  messagesTableWidget->setHorizontalHeaderLabels({"Messages", "Date", "Time"});
  messagesLayout->addWidget(messagesTableWidget, 0, 0, 1, 4);
  newMessageLineEdit = new QLineEdit(this);
  newMessageLineEdit->setPlaceholderText("Type Here...");
  newMessageLineEdit->setEnabled(false);
  messagesLayout->addWidget(newMessageLineEdit, 1, 0, 1, 3);
  sendMessageButton = new QPushButton(this);
  sendMessageButton->setText("Send");
  sendMessageButton->setEnabled(false);
  messagesLayout->addWidget(sendMessageButton, 1, 3, 1, 1);

  newChatDialog = new NewChatDialog(this, chatsTableWidget, chats);

  connect(newChatButton, SIGNAL(pressed()), this, SLOT(newChat()));
  connect(sendMessageButton, SIGNAL(pressed()), this, SLOT(sendMessage()));
  connect(newMessageLineEdit, SIGNAL(textChanged(QString)), this, SLOT(refresh()));
  connect(chatsTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(refresh()));
  connect(chatsTableWidget, SIGNAL(itemSelectionChanged()), this, SLOT(refreshMessages()));
}

ChatsWidget::~ChatsWidget() = default;

void ChatsWidget::refreshMessages() const {
  messagesTableWidget->clearContents();
  if (!chatsTableWidget->selectedItems().isEmpty()) {
    renderChat(chatsTableWidget->selectedItems().first()->text());
  }
}

void ChatsWidget::refresh() const {
  if (chatsTableWidget->selectedItems().isEmpty()) {
    sendMessageButton->setEnabled(false);
    newMessageLineEdit->setEnabled(false);
  } else {
    newMessageLineEdit->setEnabled(true);
    if (newMessageLineEdit->text().isEmpty()) {
      sendMessageButton->setEnabled(false);
    } else {
      sendMessageButton->setEnabled(true);
    }
  }
}

void ChatsWidget::sendMessage() const {
  int rows = messagesTableWidget->rowCount();
  messagesTableWidget->setRowCount(rows + 1);
  QString text = newMessageLineEdit->text();
  QString date = QDate::currentDate().toString("dd.MM.yyyy");
  QString time = QTime::currentTime().toString();
  messagesTableWidget->setItem(rows, 0, new QTableWidgetItem(text));
  messagesTableWidget->setItem(rows, 1, new QTableWidgetItem(date));
  messagesTableWidget->setItem(rows, 2, new QTableWidgetItem(time));
  messagesTableWidget->item(rows, 0)->setBackgroundColor(QColor(166, 220, 237));
  messagesTableWidget->item(rows, 1)->setBackgroundColor(QColor(166, 220, 237));
  messagesTableWidget->item(rows, 2)->setBackgroundColor(QColor(166, 220, 237));
  messagesTableWidget->resizeColumnToContents(0);
  messagesTableWidget->resizeColumnToContents(1);
  messagesTableWidget->resizeColumnToContents(2);
  QString currentChat = chatsTableWidget->selectedItems().first()->text();
  chats->operator[](currentChat).insert(chats->operator[](currentChat).size(), {
    text, date, time
  });
  newMessageLineEdit->clear();
//  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void ChatsWidget::newChat() const {
  newChatDialog->show();
//  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void ChatsWidget::renderChat(const QString &chat) const {
  if (chats->contains(chat)) {
    auto &messages = chats->operator[](chat);
    int rows = messages.size();
    messagesTableWidget->setRowCount(rows);
    for (int i = 0; i < rows; ++i) {
      messagesTableWidget->setItem(i, 0, new QTableWidgetItem(messages[i][0]));
      messagesTableWidget->setItem(i, 1, new QTableWidgetItem(messages[i][1]));
      messagesTableWidget->setItem(i, 2, new QTableWidgetItem(messages[i][2]));
      messagesTableWidget->item(i, 0)->setBackgroundColor(QColor(166, 220, 237));
      messagesTableWidget->item(i, 1)->setBackgroundColor(QColor(166, 220, 237));
      messagesTableWidget->item(i, 2)->setBackgroundColor(QColor(166, 220, 237));
    }
    messagesTableWidget->resizeColumnToContents(0);
    messagesTableWidget->resizeColumnToContents(1);
    messagesTableWidget->resizeColumnToContents(2);
  }
}
