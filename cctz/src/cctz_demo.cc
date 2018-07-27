// Author: iblisylvie@gmail.com (Qian Li)
#include <iostream>

#include "cctz/civil_time.h"

int main() {
  for (cctz::civil_day d(2016, 2, 1); d < cctz::civil_month(2016, 3); ++d) {
    std::cout << "Hello " << d;
    if (d.day() == 29) {
      std::cout << " <- leap day is a " << cctz::get_weekday(d);
    }
    std::cout << "\n";
  }
}
