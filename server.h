#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::endl;
using std::cout;


class server{

public:
    server(unsigned short port);
    string read_(tcp::socket & socket);
    void send_(tcp::socket & socket, const string& message);
    void run();

private:
    unsigned short port;
    io_context io;
    tcp::socket * socket_;
    
};