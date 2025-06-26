#include "session.h"

session::session(tcp::socket peer, int id){
    this->id = id;
    socket_ = make_unique<tcp::socket>(move(peer)); //socket toma poseción de peer
}


void session::start_session(){
    read_async();
}


void session::read_async(){
    auto self = shared_from_this();
    auto buffer = make_shared<boost::asio::streambuf>();
    
    auto read_handler = [this, self, buffer](const boost::system::error_code & ec, size_t bytes_transferred){
        if(!ec){
            cout << id <<" Mensaje Recibido" << endl;
            string msg;
            istream is(buffer.get());
            getline(is, msg);
            cerr << msg << endl; 
        }
        else{
            cerr << "Error" << ec.message() << endl;
        }

        read_async();   //sigue escuchando
    };

    boost::asio::async_read(*socket_, *buffer, boost::asio::transfer_at_least(1), read_handler);
}

void session::write_async(string message){
    auto self = shared_from_this();
    auto buff = make_shared<string>(message);

    auto write_handler = [this, self, buff](const boost::system::error_code &ec, size_t bytes_transferred){
        if(!ec) cout << "Enviado:" << bytes_transferred << endl;
        else cerr << "Error:" << ec.message() << endl;
    };

    boost::asio::async_write(*socket_, boost::asio::buffer(*buff), write_handler);
}



