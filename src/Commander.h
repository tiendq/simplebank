#ifndef COMMANDER_H
#define COMMANDER_H

#include <boost/program_options.hpp>

namespace po = boost::program_options;

namespace bank {
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
}; // bank

#endif // COMMANDER_H
