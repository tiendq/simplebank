#ifndef __BANK_H__
#define __BANK_H__

#include "Account.h"
#include "Database.h"

namespace SimpleBank {

class Bank {
public:
  Bank();
  std::string openAccount(std::string ownerName, double initialBalance);

private:
  Database m_db;
};

}; // SimpleBank

#endif // __BANK_H__
