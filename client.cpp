#include "client.h"

client::client(unsigned short port)
{
    //io_context io_service;
    socket_ = new tcp::socket(io);
    socket_->connect(tcp::endpoint(ip::make_address("127.0.0.1"), port));
}

void client::send_messsage(string message) const
{
    boost::system::error_code error;
    boost::asio::write(*socket_, boost::asio::buffer(message), error);
    if (!error){
        cout << "Client sent hello message!" << endl;
    }
    else{
        cout << "send failed: " << error.message() << endl;
    }
}

void client::run(){
    while(true){
        string msg = "hollaaaa\n";
        send_messsage(msg);

        //getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::read(*socket_, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            string data(buffers_begin(receive_buffer.data()), 
                buffers_end(receive_buffer.data()));
            cout << data << endl;
        }
    }
    

}