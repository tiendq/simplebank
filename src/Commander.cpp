#include <exception>
#include <iostream>
#include "Commander.h"

using namespace std;

namespace SimpleBank {

ostream& operator << (ostream& os, TaskList const &task) {
  os << static_cast<int>(task);
  return os;
}

TaskList Commander::start(int argc, char const *argv[]) {
  createOptionList();

  try {
    po::store(po::parse_command_line(argc, argv, m_description), m_options);
  }
  catch (po::error const &e) {
    cerr << "Error: " << e.what() << "\n";
    return TaskList::None;
  }

  if (!m_options.empty()) {
    try {
      return runTask();
    }
    catch (exception const &e) {
      cout << "Error: " << e.what() << "\n";
    }
  }

  return TaskList::None;
}

TaskList Commander::runTask() {
  if (m_options.count("help")) {
    printHelp();
    return TaskList::Help;
  }

  if (m_options.count("open-account")) {
    openAccount();
    return TaskList::OpenAccount;
  }

  if (m_options.count("close-account")) {
    closeAccount();
    return TaskList::CloseAccount;
  }

  if (m_options.count("view-account")) {
    viewAccount();
    return TaskList::ViewAccount;
  }

  if (m_options.count("list-account")) {
    listAccount();
    return TaskList::ListAccount;
  }

  if (m_options.count("deposit")) {
    depositCash();
    return TaskList::Deposit;
  }

  if (m_options.count("widthdraw")) {
    widthdrawCash();
    return TaskList::Widthdraw;
  }

  if (m_options.count("transfer")) {
    transferCash();
    return TaskList::Transfer;
  }

  if (m_options.count("list-transaction")) {
    listTransaction();
    return TaskList::ListTransaction;
  }

  if (m_options.count("interest-rate")) {
    changeInterestRate();
    return TaskList::ChangeInterestRate;
  }

  return TaskList::None;
}

void Commander::createOptionList() {
  po::options_description commands("Commands");
  auto add = commands.add_options();

  add("open-account", "Open a new account with account owner name and initial balance.");
  add("close-account", "Close an existing account, account is disabled and read only from now on.");
  add("view-account", "View detail information of an account.");
  add("list-account", "List all accounts including closed accounts.");
  add("deposit", "Deposit an amount of cash into an account.");
  add("widthdraw", "Widthdraw an amount of cash from an account.");
  add("transfer", "Transfer cash between two accounts.");
  add("list-transaction", "List transaction of an account or of all account in a period of time.");
  add("interest-rate", po::value<double>()->value_name("<rate>"),
      "Set current interest rate.");
  add("help,h", "Show list of available commands and options.");

  po::options_description options("Options");
  add = options.add_options();

  add("name", po::value<string>()->value_name("<name>"),
      "Full name of account owner of opening account.");
  add("balance", po::value<double>()->value_name("<balance>"),
      "Initial balance of opening account.");
  add("account", po::value<string>()->value_name("<number>"),
      "Account number in related commands.");
  add("amount", po::value<double>()->value_name("<amount>"),
      "Amount of cash in deposit/widthdraw/transfer commands.");
  add("source", po::value<string>()->value_name("<number>"),
      "Source account number where cash is being transferred from.");
  add("target", po::value<string>()->value_name("<number>"),
      "Target account number where cash is being transferred to.");
  add("days", po::value<int>()->value_name("<d>"),
      "Period of time in days for listing transactions, default last 30 days.");

  m_description.add(commands).add(options);
}

void Commander::printHelp() {
  cout << "Simple Bank, the command-line bank management tool\n";
  cout << "https://github.com/tiendq/simplebank\n\n";
  cout << "Usage: sb <command> [options]\n";
  cout << m_description << "\n";
}

// Required: name
// Optional: balance
void Commander::openAccount() {
  string name = "";
  double balance = 0;

  if (m_options.count("name"))
    name = m_options["name"].as<string>();
  else
    throw invalid_argument("Required option '--name' is missing");

  if (m_options.count("balance"))
    balance = m_options["balance"].as<double>();

  m_bank.openAccount(name, balance);
}

void Commander::closeAccount() {}

void Commander::viewAccount() {}

void Commander::listAccount() {}

void Commander::depositCash() {}

void Commander::widthdrawCash() {}

void Commander::transferCash() {}

void Commander::listTransaction() {}

void Commander::changeInterestRate() {}

}; // SimpleBank
