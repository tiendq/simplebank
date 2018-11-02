#include <iostream>
#include "Database.h"

using namespace std;

namespace SimpleBank {

Database::Database() : m_db("sb.db3", SQLite::OPEN_CREATE | SQLite::OPEN_READWRITE) {
  bool isNewDb = !m_db.tableExists("settings");

  if (isNewDb)
    initEmptyDb();
}

void Database::initEmptyDb() {
  SQLite::Transaction tx(m_db);

  m_db.exec("CREATE TABLE settings (id INTEGER PRIMARY KEY, interest_rate REAL)");
  m_db.exec("INSERT INTO settings VALUES (NULL, 12.0)");
  m_db.exec("CREATE TABLE accounts (id INTEGER PRIMARY KEY, account_number TEXT, onwer_name TEXT, balance REAL, status INTEGER, created_time INTEGER)");
  m_db.exec("CREATE TABLE transactions (id INTEGER PRIMARY KEY)");

  tx.commit();
}

int Database::openAccount(Account const &account) {
  SQLite::Statement query(m_db, "INSERT INTO accounts VALUES (NULL, ?, ?, ?, ?, ?)");

  query.bind(1, account.m_number);
  query.bind(2, account.m_owner);
  query.bind(3, account.m_balance);
  query.bind(4, static_cast<int>(account.m_status));
  query.bind(5, account.m_created);

  int id = query.exec();
  return id;
}

};
