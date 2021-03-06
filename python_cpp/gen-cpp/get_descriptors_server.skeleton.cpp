// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "get_descriptors.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

class get_descriptorsHandler : virtual public get_descriptorsIf {
 public:
  get_descriptorsHandler() {
    // Your initialization goes here
  }

  void return_descriptors(std::vector<double> & _return, const std::vector<double> & input) {
    // Your implementation goes here
    printf("return_descriptors\n");
  }

  void match_descriptors(std::vector<int32_t> & _return, const std::vector<double> & feature_1, const std::vector<double> & feature_2) {
    // Your implementation goes here
    printf("match_descriptors\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<get_descriptorsHandler> handler(new get_descriptorsHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new get_descriptorsProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

