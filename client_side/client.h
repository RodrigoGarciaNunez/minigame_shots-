#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include <utility>

using namespace boost::asio;
using std::cout;
using ip::tcp;
using std::string;
using std::endl;
using std::cerr;
using std::size_t;
using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;
using std::enable_shared_from_this;
using std::thread;
using std::istream;
using std::getline;
using std::pair;

class client: public enable_shared_from_this<client>{
public:
    client(int id, unsigned short port=3000);
    void send_async_messsage(string message);  //no pueden ser const
    void read_async_message();
    void run();
    io_context io;

private:
    unsigned short PORT;
    unique_ptr<tcp::socket>  socket_;
    boost::system::error_code error;
    int id;
    thread io_runner;

};