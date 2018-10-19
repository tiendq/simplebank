#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include <boost/program_options.hpp>

namespace po = boost::program_options;

namespace SimpleBank {
enum class TaskList {
  None,
  Help,
  OpenAccount
};

std::ostream& operator << (std::ostream& os, TaskList const &task);

class Commander {
public:
  TaskList start(int argc, char const *argv[]);

private:
  void createOptionList();
  void printHelp();
  TaskList runTask();

  po::options_description m_description;
  po::variables_map m_options;
};
}; // SimpleBank

#endif // __COMMANDER_H__
