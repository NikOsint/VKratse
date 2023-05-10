//
// Created by nikosint on 10.05.23.
//

#include "chats_widget.h"

ChatsWidget::ChatsWidget(QWidget* parent) : QWidget(parent) {

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
  messagesTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
  messagesTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
  messagesTableWidget->setColumnCount(3);
  messagesTableWidget->setHorizontalHeaderLabels({"Messages", "Date", "Time"});
  messagesLayout->addWidget(messagesTableWidget, 0, 0, 1, 4);
  newMessageLineEdit = new QLineEdit(this);
  newMessageLineEdit->setPlaceholderText("Type Here...");
//  newMessageLineEdit->setEnabled(false);
  messagesLayout->addWidget(newMessageLineEdit, 1, 0, 1, 3);
  sendMessageButton = new QPushButton(this);
  sendMessageButton->setText("Send");
  sendMessageButton->setEnabled(false);
  messagesLayout->addWidget(sendMessageButton, 1, 3, 1, 1);

  newChatDialog = new NewChatDialog(this, chatsTableWidget);

  connect(newChatButton, SIGNAL(pressed()), this, SLOT(newChat()));
  connect(sendMessageButton, SIGNAL(pressed()), this, SLOT(sendMessage()));
  connect(newMessageLineEdit, SIGNAL(textChanged(QString)), this, SLOT(refresh()));
}

ChatsWidget::~ChatsWidget() = default;

void ChatsWidget::refresh() const {
  if (newMessageLineEdit->text().isEmpty()) {
    sendMessageButton->setEnabled(false);
  } else {
    sendMessageButton->setEnabled(true);
  }
}

void ChatsWidget::sendMessage() const {
  int rows = messagesTableWidget->rowCount();
  messagesTableWidget->setRowCount(rows + 1);
  messagesTableWidget->setItem(rows, 0, new QTableWidgetItem(newMessageLineEdit->text()));
  messagesTableWidget->setItem(rows, 1, new QTableWidgetItem(QDate::currentDate().toString("dd.MM.yyyy")));
  messagesTableWidget->setItem(rows, 2, new QTableWidgetItem(QTime::currentTime().toString()));
  messagesTableWidget->resizeColumnToContents(0);
  messagesTableWidget->resizeColumnToContents(1);
  newMessageLineEdit->clear();
//  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void ChatsWidget::newChat() const {
  newChatDialog->show();
//  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}
