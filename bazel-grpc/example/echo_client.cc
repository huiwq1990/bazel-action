#include "example/echo.grpc.pb.h"
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/security/credentials.h>
#include <iostream>
#include <memory>
#include <string>

using grpc::Channel;
using grpc::ClientContext;
using grpc::CreateChannel;
using grpc::InsecureChannelCredentials;
using grpc::Status;
using echo::EchoRequest;
using echo::EchoResponse;
using echo::EchoService;

class EchoClient {
public:
  EchoClient(std::shared_ptr<Channel> channel)
      : stub_(EchoService::NewStub(channel)) {}

  std::string echo(const std::string &text) {
    EchoRequest req;
    req.set_text(text);
    EchoResponse res;
    ClientContext context;
    Status status = stub_->echo(&context, req, &res);
    if (status.ok()) {
      return res.result();
    } else {
      std::cout << status.error_code() << ": " << status.error_message()
                << std::endl;
      return "RPC failed";
    }
  }

private:
  std::unique_ptr<EchoService::Stub> stub_;
};

int main(int argc, char *argv[]) {

    // local run not need http proxy
    char *httpProxy="http_proxy";
    unsetenv(httpProxy);

    //std::cout << "env http_proxy value:" << getenv(httpProxy) << std::endl;
//    if (putenv("http_proxy=") == 0){
//        std::cout << "set http_proxy." << std::endl;
//    }


        EchoClient client(
      CreateChannel("127.0.0.1:50051", InsecureChannelCredentials()));
  std::string text;
    std::cout << "start call." << std::endl;

   auto ret = client.echo("aaa");
    std::cout << "ssssss: " << ret << std::endl;


    while (std::getline(std::cin, text)) {
    auto reply = client.echo(text);
    std::cout << "Received: " << reply << std::endl;
  }
  return 0;
}
