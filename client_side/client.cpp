#include "client.h"

client::client(int i,unsigned short port)
{
    //io_context io_service;
    id = i;
    socket_ = make_unique<tcp::socket>(io);
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
    auto read_handler = [](const boost::system::error_code& ec, std::size_t bytes_transferred) {
        if (!ec) {
            std::cout << "Recibido: " << bytes_transferred << " bytes\n";
        } else {
            std::cerr << "Error: " << ec.message() << "\n";
        }
    };
    
    while(true){
        string msg = "hola, servidor! Soy "+std::to_string(id)+"\n";
        send_messsage(msg);

        //getting response from server
        boost::asio::streambuf receive_buffer;
        boost::asio::async_read(*socket_, receive_buffer, boost::asio::transfer_at_least(1),read_handler) ;  //transfer_all es bloqueante y solo para la versión sincrónica
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