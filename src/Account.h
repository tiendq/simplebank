#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <ctime>
#include <string>

namespace SimpleBank {

enum class AccountStatus {
  Active, Closed
};

struct Account {
  std::string m_number;
  std::string m_owner;
  double m_balance;
  AccountStatus m_status;
  std::time_t m_created;
};

}; // SimpleBank

#endif // __ACCOUNT_H__
