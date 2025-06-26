#include <iostream>
#include <memory>
#include <boost/asio.hpp>

using namespace boost::asio;
using std::enable_shared_from_this;
using ip::tcp;
using std::unique_ptr;
using std::shared_ptr;
using std::make_shared;
using std::make_unique;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::istream;
using std::move;

class session: public enable_shared_from_this<session>{
public:
   session(tcp::socket peer, int id);
   void start_session(); 
private:

    void read_async();
    void write_async(string message);

    int id;
    unique_ptr<tcp::socket> socket_;

};