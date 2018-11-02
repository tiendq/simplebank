// Exclude main.cpp from to not duplicate main() with Boost's default.
#ifndef BOOST_UNIT_TEST

#include <iostream>
#include "Commander.h"

using namespace std;
using namespace SimpleBank;

int main(int argc, char const *argv[]) {
  if (argc <= 1) {
    cout << "Use --help for list of available commands and options.\n";
  }
  else {
    Commander cmd;
    cmd.start(argc, argv);
  }

  return 0;
}

#endif // BOOST_UNIT_TEST
