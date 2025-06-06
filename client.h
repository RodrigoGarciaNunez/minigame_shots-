#include <boost/asio.hpp>
#include <iostream>

using namespace boost::asio;
using std::cout;
using ip::tcp;
using std::string;
using std::endl;

class client{
public:
    client(unsigned short port);
    void send_messsage(string message)const;
    void run();

private:
    unsigned short PORT;
    io_context io;
    tcp::socket * socket_;
    boost::system::error_code error;

};