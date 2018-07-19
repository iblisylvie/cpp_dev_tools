// Author: iblisylvie@gmail.com (Qian Li)

#include <glog/logging.h>

int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  LOG(INFO) << "print by log info";
  LOG(ERROR) << "print by log error";
  LOG(WARNING) << "print by log warning";

  VLOG(1) << "print by vlog 1";
  VLOG(2) << "print by vlog 2";
  VLOG(3) << "print by vlog 3";
  if (VLOG_IS_ON(2)) {
    LOG(INFO) << "print by vlog 2";
    LOG(INFO) << "print by vlog 2";
  }
  bool condition = false;
  VLOG_IF(1, condition) << "print by log if";
  condition = true;
  VLOG_IF(1, condition) << "print by log if";

  int a = 1;
  int b = 1;
  int c = 2;
  CHECK_EQ(a, b);
  CHECK_GT(c, a);
  //  LOG(FATAL) << "print by log fatal";

  return 0;
}
