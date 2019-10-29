// Author: iblisylvie@gmail.com (Qian Li)

#include <iostream>
#include <memory>
#include <string>
#include <sstream>

#include "proto/helloworld.grpc.pb.h"
#include "grpc++/grpc++.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class GreeterServiceImpl : public Greeter::Service {
public:
  GreeterServiceImpl() {}

  Status SayHello(ServerContext* context, const HelloRequest* request,
                  HelloReply* reply) {
    std::cout << "receive request:" << request->id() << std::endl;
    std::string prefix("Hello ");
    std::stringstream oss;
    oss << "Hello " << request->id();
    reply->set_message(oss.str());
    return Status::OK;
  }
};

void RunServer() {
  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;
  ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
  std::cout << "Server exit." << std::endl;
}

int main(int argc, char** argv) {

  RunServer();

  return 0;
}
