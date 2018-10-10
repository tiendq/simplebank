#include <iostream>
#include "Commander.h"

using namespace std;

namespace SimpleBank {
void Commander::start(int argc, char const *argv[]) {
  createOptionList();

  try {
    po::store(po::parse_command_line(argc, argv, m_description), m_options);
  }
  catch (po::error const &e) {
      cerr << "Error: " << e.what() << "\n";
  }

  if (!m_options.empty())
    runTask();
}

void Commander::runTask() {
  if (m_options.count("help")) {
    printHelp();
  }
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
      "Full name of account owner.");
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
  add("time", po::value<int>()->value_name("<days>"),
      "Period of time in days for listing transactions, default last 30 days.");

  m_description.add(commands).add(options);
}

void Commander::printHelp() {
  cout << "Usage: sb <command> [option]\n\n";
  cout << m_description << "\n";
}
}; // SimpleBank
