#ifndef COMMANDER_H
#define COMMANDER_H

#include <boost/program_options.hpp>

namespace bank {
  class Commander {
    public:
      void start(int argc, char const *argv[]);

    private:
      void createOptionList();
      void printHelp();
      void runTask();

      boost::program_options::options_description m_description;
      boost::program_options::variables_map m_options;
  };
}; // bank

#endif // COMMANDER_H
