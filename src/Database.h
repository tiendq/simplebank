#ifndef __DATABASE_H__
#define __DATABASE_H__

#include <SQLiteCpp/SQLiteCpp.h>
#include "Account.h"

namespace SimpleBank {

class Database {
public:
  Database();
  int openAccount(Account const &account);

private:
  void initEmptyDb();

  SQLite::Database m_db;
};

}; // SimpleBank

#endif // __DATABASE_H__
