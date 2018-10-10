#ifndef __COMMANDER_H__
#define __COMMANDER_H__

#include <boost/program_options.hpp>

namespace po = boost::program_options;

namespace SimpleBank {
class Commander {
public:
  void start(int argc, char const *argv[]);

private:
  void createOptionList();
  void printHelp();
  void runTask();

  po::options_description m_description;
  po::variables_map m_options;
};
}; // SimpleBank

#endif // __COMMANDER_H__
