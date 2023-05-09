//
// Created by nikosint on 09.05.23.
//

#ifndef VKRATSECLIENT_MAINWINDOW_H
#define VKRATSECLIENT_MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

#include "authorization_dialog.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

protected:
  QTabWidget *tabWidget;
  QGridLayout *layout, *chatsLayout, *settingsLayout;
  AuthorizationDialog *authorizationWidget;
  QWidget *chatsWidget, *settingsWidget;

public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override;

//  void begin() const;

public slots:
//  void refresh() const;
//  void checkBook() const;
//  void checkType() const;
//  void checkFType() const;
//  void checkQuan() const;
//  void checkFilter() const;
//  void showFilter();
//  void clearParam() const;
//  void importTxt();
//  void xportTxt() const;
//  void importExcel();
//  void xportExcel() const;
//  void clear();
//  void link() const;
//  void addBook();
//  void plus();
//  void minus();
//  void changeQuan();
};

#endif //VKRATSECLIENT_MAINWINDOW_H
