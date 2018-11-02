#include <chrono>
#include <iostream>
#include "Bank.h"

using namespace std;
using namespace std::chrono;

namespace SimpleBank {

Bank::Bank() {}

string Bank::openAccount(string ownerName, double initialBalance) {
  time_t createdTime = system_clock::to_time_t(system_clock::now());
  string number = "SB" + to_string(createdTime);

  Account account{number, ownerName, initialBalance, AccountStatus::Active, createdTime};
  int id = m_db.openAccount(account);

  return number;
}

};
