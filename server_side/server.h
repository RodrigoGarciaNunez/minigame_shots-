#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::endl;
using std::cout;
using std::unique_ptr;
using std::make_unique;

class server{

public:
    server(unsigned short port=3000);
    string read_(tcp::socket & socket);
    void send_(tcp::socket & socket, const string& message);
    void run();

private:
    unsigned short port;
    io_context io;
    unique_ptr<tcp::socket> socket_;
    unique_ptr<tcp::acceptor> acceptor;
};