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

class NewChatDialog : public QDialog {
  Q_OBJECT

protected:
  QGridLayout *layout;
  QLabel *newChatLabel;
  QLineEdit *newChatLineEdit;
  QPushButton *createChatButton, *cancelButton;
  QTableWidget *chatsTableWidget;

public:
  explicit NewChatDialog(QWidget* parent = nullptr, QTableWidget* chatsTableWidget = nullptr);
  ~NewChatDialog() override;

public slots:
  void refresh() const;
  void createChat();
  void cancel();
};

#endif //VKRATSECLIENT_NEW_CHAT_DIALOG_H
