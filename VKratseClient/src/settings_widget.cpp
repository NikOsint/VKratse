//
// Created by nikosint on 09.05.23.
//

#include "settings_widget.h"

SettingsWidget::SettingsWidget(QWidget* parent,
                               AuthorizationDialog* authorizationDialog,
                               VKratseUser* user,
                               bool isDarkTheme)
                               : QWidget(parent) {

  this->mainWindow = parent;
  this->authorizationDialog = authorizationDialog;
  this->user = user;
  this->isDarkTheme = isDarkTheme;

  layout = new QGridLayout(this);
  this->setLayout(layout);

  leftFrame = new QFrame(this);
  layout->addWidget(leftFrame, 0, 0, 1, 1);
  rightFrame = new QFrame(this);
  layout->addWidget(rightFrame, 0, 2, 1, 1);
  centerFrame = new QFrame(this);
  centerFrame->setFrameShape(QFrame::Shape::Panel);
  centerFrame->setFrameShadow(QFrame::Shadow::Plain);
  centerFrame->setLineWidth(1);
  centerFrame->setMidLineWidth(1);
  layout->addWidget(centerFrame, 0, 1, 1, 1);

  centerFrameLayout = new QGridLayout(centerFrame);
  centerFrame->setLayout(centerFrameLayout);

  setAvatar("../resources/default.jpg");
  avatarLabel = new QLabel(this);
  avatarLabel->setPixmap(*avatar);
  avatarLabel->setAlignment(Qt::AlignCenter);
  centerFrameLayout->addWidget(avatarLabel, 0, 0, 1, 1);

  nameSurnameLabel = new QLabel(this);
  updateUser();
  nameSurnameLabel->setAlignment(Qt::AlignCenter);
  nameSurnameLabel->setTextFormat(Qt::TextFormat::RichText);
  nameSurnameLabel->setFrameShape(QFrame::Shape::Panel);
  nameSurnameLabel->setFrameShadow(QFrame::Shadow::Plain);
  nameSurnameLabel->setLineWidth(1);
  nameSurnameLabel->setMidLineWidth(1);
  centerFrameLayout->addWidget(nameSurnameLabel, 1, 0, 1, 1);

  changeAvatarButton = new QPushButton(this);
  changeAvatarButton->setText("Change Avatar");
  centerFrameLayout->addWidget(changeAvatarButton, 2, 0, 1, 1);

  changePasswordButton = new QPushButton(this);
  changePasswordButton->setText("Change Password");
  centerFrameLayout->addWidget(changePasswordButton, 3, 0, 1, 1);

  changeThemeButton = new QPushButton(this);
  changeThemeButton->setText("Set Dark Theme");
  centerFrameLayout->addWidget(changeThemeButton, 4, 0, 1, 1);

  logOutButton = new QPushButton(this);
  logOutButton->setText("Log Out");
  centerFrameLayout->addWidget(logOutButton, 5, 0, 1, 1);

  connect(changeAvatarButton, SIGNAL(pressed()), this, SLOT(changeAvatar()));
  connect(changePasswordButton, SIGNAL(pressed()), this, SLOT(changePassword()));
  connect(changeThemeButton, SIGNAL(pressed()), this, SLOT(changeTheme()));
  connect(logOutButton, SIGNAL(pressed()), this, SLOT(logOut()));
  connect(authorizationDialog, SIGNAL(logInSuccessful()), this, SLOT(updateUser()));
}

SettingsWidget::~SettingsWidget() = default;

void SettingsWidget::setAvatar(const QString &filename) {
  QPixmap pm(filename);
  if (pm.isNull()) {
    QMessageBox::warning(nullptr, "Error Loading Avatar", "Can not open file " + filename);
    avatar = new QPixmap(QSize(600, 600));
    return;
  }
  if (pm.size().height() > 600 || pm.size().width() > 600){
    pm = pm.scaled(600, 600);
  }
  avatar = new QPixmap(pm);
}

void SettingsWidget::updateUser() const {
  if (user && user->isValid()) {
    nameSurnameLabel->setText(user->getNameSurname());
  } else {
    nameSurnameLabel->setText("Name Surname");
  }
}

void SettingsWidget::changeAvatar() const {
  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void SettingsWidget::changePassword() const {
  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void SettingsWidget::changeTheme() const {
  QMessageBox::information(nullptr, "Unimplemented Feature", "This feature is currently under development"); //TODO
}

void SettingsWidget::logOut() const {
  if (mainWindow && authorizationDialog) {
    mainWindow->setEnabled(false);
    authorizationDialog->setEnabled(true);
    authorizationDialog->show();
  } else {
    QMessageBox::warning(nullptr, "Log Out Error",
                         "ERROR: can not log out properly\nPlease, close the application - it will log you out");
  }
}
