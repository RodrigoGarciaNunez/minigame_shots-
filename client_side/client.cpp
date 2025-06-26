#include "client.h"

client::client(int i,unsigned short port)
{
    //io_context io_service;
    id = i;
    socket_ = make_unique<tcp::socket>(io);
    socket_->connect(tcp::endpoint(ip::make_address("127.0.0.1"), port));
    cout << "Cliente " << id << " incializado" << endl;
}

void client::send_async_messsage(string message)
{
    auto self = shared_from_this();
    auto buff = make_shared<string>(message);  // io inicializa y envía a error code internamente
    
    auto write_handler = [this, self, buff](const boost::system::error_code &ec, size_t bytes_transferred){
        if (!ec) cerr << "Enviado : " << bytes_transferred << " bytes\n";
        else cerr << "Error: " << ec.message() << "\n";
    }; 

    boost::asio::async_write(*socket_, boost::asio::buffer(*buff), write_handler);

    //read_async_message();
}


void client::read_async_message(){
    auto self = shared_from_this();
    auto buffer= make_shared<boost::asio::streambuf>();
    string msg;

    auto read_handler = [this, self, buffer](const boost::system::error_code& ec, size_t bytes_transferred) {
        if (!ec) cerr << "Recibido: " << bytes_transferred << " bytes\n";
        else cerr << "Error: " << ec.message() << "\n";
        
    };
    
    boost::asio::async_read(*socket_, *buffer, boost::asio::transfer_at_least(1), read_handler);

    istream is(buffer.get());
    getline(is, msg);
    cerr << "recibido" << msg << endl; 
    //send_async_messsage("Hola");
}

// void client::run(){
//     auto read_handler = [](const boost::system::error_code& ec, std::size_t bytes_transferred) {
//         if (!ec) {
//             cerr << "Recibido: " << bytes_transferred << " bytes\n";
//         } else {
//             cerr << "Error: " << ec.message() << "\n";
//         }
//     };
    
//     while(true){
//         string msg = "hola, servidor! Soy "+std::to_string(id)+"\n";
//         send_async_messsage(msg);
//         boost::asio::streambuf receive_buffer;
//         boost::asio::async_read(*socket_, receive_buffer, boost::asio::transfer_at_least(1),read_handler) ;  //transfer_all es bloqueante y solo para la versión sincrónica
//         //boost::asio::read(*socket_, receive_buffer,  boost::asio::transfer_all(), error);
//         //if( error && error != boost::asio::error::eof ) {
//             //cout << "receive failed: " << error.message() << endl;
//         //}
//         //else {
//             cout << "recibí mensaje" << endl;
//             
//         //}
//     }
//}