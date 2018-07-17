// Author: iblisylvie@gmail.com (Qian Li)
// port from https://github.com/google/re2/wiki/CplusplusAPI
#include <cassert>

#include "re2/re2.h"

namespace re2 {
class RE2;
}  // namespace re2

int main() {
  assert(RE2::FullMatch("hello", "h.*o"));
  assert(!RE2::FullMatch("hello", "e"));

  assert(RE2::PartialMatch("hello", "h.*o"));
  assert(RE2::PartialMatch("hello", "e"));
  return 0;
}
