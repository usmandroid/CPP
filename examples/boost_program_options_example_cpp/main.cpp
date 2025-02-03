//$ g++ main.cpp -o main -lboost_program_options -lboost_system
//-lboost_filesystem; $ ./main --help
// Example usage: $ ./main --str1 /home/bin/dir --int1 5 --str2 execute
#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/program_options.hpp>
#include <boost/regex.hpp>
#include <boost/thread/thread.hpp>
#include <fcntl.h>
#include <iostream>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Setup the program options
  uint32_t var1;
  std::string var2, var3;
  double var4, var5, var6;
  // clang-format off
  namespace po = boost::program_options;
  po::options_description desc("Allowed options");
  desc.add_options()
  ("help", "help message")
  ("int1", po::value<uint32_t>(&var1)->default_value(0),"Integer input.")
  ("str1", po::value<std::string>(&var2)->default_value("5444"), "String Input 1.")
  ("str2", po::value<std::string>(&var3)->default_value(""), "String Input 2.")
  ("dbl1", po::value<double>(&var4)->default_value(5.2),"Double Input 1")
  ("dbl2", po::value<double>(&var5)->default_value(-3.2), "Double Input 2.")
  ("poke", po::value<double>(&var6)->default_value(2.1), "Double Input 3.")
  ("stats", "Show some stats.");
  // clang-format on
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  // Print the help message
  if (vm.count("help")) {
    std::cout << boost::format(
                     "Simple Example of boost program options\n\n %s") %
                     desc
              << std::endl;
    return ~0;
  }
  // Print explicitly provided arguments
  for (const auto &option : vm) {
    if (!option.second.defaulted()) {
      std::cout << "Option: " << option.first << " Value: ";
      auto &value = option.second.value();
      if (auto v = boost::any_cast<uint32_t>(&value))
        std::cout << *v;
      else if (auto v = boost::any_cast<std::string>(&value))
        std::cout << *v;
      else if (auto v = boost::any_cast<double>(&value))
        std::cout << *v;
      std::cout << std::endl;
    }
  }
  // Execute arbitrary conditional code based on str2
  if (vm.count("str2")) {
    std::cout << "str2 provided with value: " << vm["str2"].as<std::string>()
              << std::endl;
    // Arbitrary conditional code
    if (vm["str2"].as<std::string>() == "execute") {
      std::cout
          << "Executing arbitrary conditional code because str2 is 'execute'"
          << std::endl;
      // Add your arbitrary code here
    }
  }

  return 0;
}
