#include <iostream>
#include "Commander.h"

/*
--open-account account-owner initial-balance
--close-account account-number
--list-account
--view-account account-number
--deposit account-number amount
--widthraw account-number amount
--transfer from-account to-account amount
--list-transaction account-number or last 10 transactions or last 30 days

interest? update once a day, check for update when run
data file?
*/

using namespace std;
using namespace boost::program_options;

namespace bank {
  void Commander::start(int argc, char const *argv[]) {
    createOptionList();

    try {
      store(parse_command_line(argc, argv, m_description), m_options);
    }
    catch (error const &e) {
      cerr << e.what() << "\n";
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
    options_description options("Options");
    auto add = options.add_options();

    add("open-account", value<string>()->value_name("<account owner>"),
        "Open a new account with account owner name and initial balance.");
    add("help,h", "Show list of available commands and options.");

    m_description.add(options);
  }

  void Commander::printHelp() {
    cout << m_description;
  }
}; // bank
