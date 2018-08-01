// Author: iblisylvie@gmail.com (Qian Li)

#include "file.h"

#include "gtest/gtest.h"

using namespace iblis;

TEST (FileTest, FileExists) {
  EXPECT_FALSE(File::Exists("this_file_doesnt_exist"));
  EXPECT_TRUE(File::Exists("file/testdata/testfile.txt"));
}

TEST (FileTest, ReadFileToString) {
  string content = "";
  bool success = File::ReadFileToString("file/testdata/testfile.txt", &content);
  ASSERT_TRUE(success);
  ASSERT_EQ("Hello World!", content);
}
