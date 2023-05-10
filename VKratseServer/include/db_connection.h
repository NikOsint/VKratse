//
// Created by nikosint on 10.05.23.
//

#ifndef VKRATSESERVER_DB_CONNECTION_H
#define VKRATSESERVER_DB_CONNECTION_H

#include <QtSql>
#include <QSqlDatabase>

inline bool connectDb() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
  db.setHostName("127.0.0.1");
  db.setDatabaseName("vkratse_server");
  db.setUserName("postgres"); // set what you need
  db.setPassword("password"); // set what you need
  return db.open();
}

inline bool createTables() {
  QSqlQuery query;
  query.exec("CREATE TABLE IF NOT EXISTS \"vkratse_users\" ("
             "\"username\" varchar(50) PRIMARY KEY,"
             "\"password_hash\" text NOT NULL,"
             "\"avatar_file\" text DEFAULT NULL,"
             "\"name\" varchar(50) NOT NULL,"
             "\"surname\" varchar(50) NOT NULL");
  query.exec("CREATE TABLE IF NOT EXISTS \"vkratse_messages\" ("
             "\"message_id\" bigserial PRIMARY KEY,"
             "\"from\" varchar(50) NOT NULL REFERENCES \"vkratse_users\"(\"username\"),"
             "\"to\" varchar(50) NOT NULL REFERENCES \"vkratse_users\"(\"username\"),"
             "\"message_text\" text NOT NULL,"
             "\"message_timestamp\" timestamp NOT NULL");
  return true;
}

#endif //VKRATSESERVER_DB_CONNECTION_H
