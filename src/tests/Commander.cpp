#include <boost/test/unit_test.hpp>
#include "Commander.h"

using namespace SimpleBank;

BOOST_AUTO_TEST_SUITE(CommanderTests)

BOOST_AUTO_TEST_CASE(ctor) {
  Commander cmd;
}

BOOST_AUTO_TEST_CASE(NoOptionProvided) {
  int argc = 1;
  char const *argv[] = { "sb" };

  Commander cmd;
  TaskList task = cmd.start(argc, argv);

  BOOST_TEST(TaskList::None == task);
}

BOOST_AUTO_TEST_CASE(HelpOptionProvided) {
  int argc = 2;
  char const *argv[] = { "sb", "--help" };

  Commander cmd;
  TaskList task = cmd.start(argc, argv);

  BOOST_TEST(TaskList::Help == task);
}

BOOST_AUTO_TEST_SUITE_END()
