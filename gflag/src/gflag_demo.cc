// Author: iblisylvie@gmail.com (Qian Li)

#include <iostream>

#include <gflags/gflags.h>

DEFINE_bool(big_menu, true, "Include 'advanced' options in the menu listing");
DEFINE_string(languages, "english,french,german",
              "comma-separated list of languages to offer in the 'lang' menu");

int main(int argc, char** argv) {
  google::ParseCommandLineFlags(&argc, &argv, false);
  std::cout << FLAGS_big_menu << std::endl;
  std::cout << FLAGS_languages << std::endl;
  return 0;
}
