// Author: iblisylvie@gmail.com (Qian Li)

#include <math.h>  // sqrt

#include "gtest/gtest.h"
 
TEST (SquareRootTest, PositiveNos) { 
  EXPECT_EQ (18.0, sqrt(324.0));
  EXPECT_EQ (25.4, sqrt(645.16));
  EXPECT_EQ (50.332, sqrt(2533.310224));
}
 
TEST (SquareRootTest, ZeroAndNegativeNos) { 
  ASSERT_EQ (0.0, sqrt(0.0));
  ASSERT_TRUE (std::isnan(sqrt(-22.0)));
}