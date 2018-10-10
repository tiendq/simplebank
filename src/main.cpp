#include <iostream>
#include "Commander.h"

using namespace std;
using namespace SimpleBank;

int main(int argc, char const *argv[]) {
  cout << "Simple Bank, the command-line bank management tool\n";
  cout << "https://github.com/tiendq/simplebank\n";

  if (argc <= 1) {
    cout << "Use --help for list of available commands and options.\n";
  }
  else {
    Commander cmd;
    cmd.start(argc, argv);
  }

  return 0;
}
