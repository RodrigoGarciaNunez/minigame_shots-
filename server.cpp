#include "server.h"

server::server(unsigned short PORT){
    port = PORT;
    //io_service
    //io_context io_service;
    //listent for a new connection
    tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), port));
    
    //socket creation 
    socket_ = new tcp::socket(io);
    //waiting for connection
    acceptor.accept(*socket_);
}


string server::read_(tcp::socket & socket) {
       boost::asio::streambuf buf;
       boost::asio::read_until(socket, buf, "\n" );
       string data(buffers_begin(buf.data()),
            buffers_end(buf.data()));
       return data;
}


void server::send_(tcp::socket & socket, const string& message) {
       const string msg = message + "\n";
       boost::asio::write( socket, boost::asio::buffer(message) );
}

void server::run(){
    while(true){
        string message = read_(*socket_);
        cout << message << endl;
        send_(*socket_, "Hello From Server!");
        cout << "Servent sent Hello message to Client!" << endl;
    }
    
}