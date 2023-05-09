//
// Created by nikosint on 09.05.23.
//

#ifndef VKRATSECLIENT_SETTINGS_WIDGET_H
#define VKRATSECLIENT_SETTINGS_WIDGET_H

#include <QPixmap>
#include <QFrame>

#include "authorization_dialog.h"

class SettingsWidget : public QWidget {
  Q_OBJECT

protected:
  bool isDarkTheme;
  QGridLayout *layout, *centerFrameLayout;
  QLabel *avatarLabel, *nameSurnameLabel;
  QPushButton *changeAvatarButton, *changePasswordButton, *changeThemeButton, *logOutButton;
  QFrame *leftFrame, *rightFrame, *centerFrame;
  QPixmap *avatar;
  QWidget *mainWindow;
  AuthorizationDialog *authorizationDialog;

public:
  explicit SettingsWidget(QWidget* parent = nullptr,
                          AuthorizationDialog* authorizationDialog = nullptr,
                          bool isDarkTheme = false);
  ~SettingsWidget() override;

  void setAvatar(const QString &filename);

public slots:
  void changeAvatar() const;
  void changePassword() const;
  void changeTheme() const;
  void logOut() const;
};

#endif //VKRATSECLIENT_SETTINGS_WIDGET_H
