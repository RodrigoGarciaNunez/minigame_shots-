#include <boost/asio.hpp>
#include <iostream>
#include <memory>
#include "session.h"

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::endl;
using std::cout;
using std::cerr;
using std::unique_ptr;
using std::make_unique;
using std::make_shared;
using std::shared_ptr;
using std::enable_shared_from_this;
using std::thread;
using std::istream;
using std::vector;

class server: public enable_shared_from_this<server>{

public:
    server(unsigned short port=3000);
    //void read_async();
    //void send_async(const string& message);

    void async_accept();
    void run();
    io_context io_context_;
    //unique_ptr<vector<tcp::socket>> socket_;

private:
    unsigned short port;
    thread io_runner;
    shared_ptr<tcp::acceptor> acceptor;
    vector<shared_ptr<session>> clients;
};