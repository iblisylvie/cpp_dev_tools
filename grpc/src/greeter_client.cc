// Author: iblisylvie@gmail.com (Qian Li)

#include <iostream>
#include <memory>
#include <string>

#include "proto/helloworld.grpc.pb.h"
#include "grpc++/grpc++.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Greeter;

class GreeterClient {
 public:
  GreeterClient(std::shared_ptr<Channel> channel)
      : stub_(Greeter::NewStub(channel)) {}

  std::string SayHello(const int id) {
    while (true) {
      // Data we are sending to the server.
      HelloRequest request;
      request.set_id(id);

      // Container for the data we expect from the server.
      HelloReply reply;

      // Context for the client. It could be used to convey extra information to
      // the server and/or tweak certain RPC behaviors.
      ClientContext context;

      // set grpc timeout.
      const auto start_time = std::chrono::system_clock::now();
      const std::chrono::system_clock::time_point deadline = start_time
          + std::chrono::milliseconds(1000);
      context.set_deadline(deadline);
      // The actual RPC.
      Status status = stub_->SayHello(&context, request, &reply);

      // Act upon its status.
      if (status.ok()) {
        return reply.message();
      } else {
        std::cout << "RPC failed, try again!" << std::endl;
      }
    }
  }

 private:
  std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
  GreeterClient greeter(
      grpc::CreateChannel("localhost:50051",
                          grpc::InsecureChannelCredentials()));
  int doc_id = 0;
  while (doc_id < 5) {
    std::string reply = greeter.SayHello(doc_id);
    doc_id++;
    std::cout << "Client get reply: " << reply << std::endl;
  }

  return 0;
}
