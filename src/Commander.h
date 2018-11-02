#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include <boost/program_options.hpp>
#include "Bank.h"

namespace po = boost::program_options;

namespace SimpleBank {

enum class TaskList {
  None,
  Help,
  OpenAccount,
  CloseAccount,
  ViewAccount,
  ListAccount,
  Deposit,
  Widthdraw,
  Transfer,
  ListTransaction,
  ChangeInterestRate
};

std::ostream& operator << (std::ostream& os, TaskList const &task);

class Commander {
public:
  TaskList start(int argc, char const *argv[]);

private:
  void createOptionList();
  TaskList runTask();
  void printHelp();
  void openAccount();
  void closeAccount();
  void viewAccount();
  void listAccount();
  void depositCash();
  void widthdrawCash();
  void transferCash();
  void listTransaction();
  void changeInterestRate();

  po::options_description m_description;
  po::variables_map m_options;
  Bank m_bank;
};

}; // SimpleBank

#endif // __COMMANDER_H__
