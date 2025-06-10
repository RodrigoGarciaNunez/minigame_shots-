#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using namespace boost::asio;
using std::cout;
using ip::tcp;
using std::string;
using std::endl;
using std::cerr;
using std::size_t;
using std::make_unique;
using std::unique_ptr;

class client{
public:
    client(int id, unsigned short port=3000);
    void send_messsage(string message)const;
    void run();

private:
    unsigned short PORT;
    io_context io;
    unique_ptr<tcp::socket>  socket_;
    boost::system::error_code error;
    int id;

};