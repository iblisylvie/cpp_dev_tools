// Author: iblisylvie@gmail.com (Qian Li)

#include <iostream>

#include "absl/strings/strip.h"

int main(int argc, char** argv) {
  // strip string
  std::string msg = " Leading space. ";
  absl::RemoveExtraAsciiWhitespace(&msg);
  std::cout << msg << std::endl;
  assert(strcmp("Leading space.", msg.c_str()) == 0);
  return 0;
}
