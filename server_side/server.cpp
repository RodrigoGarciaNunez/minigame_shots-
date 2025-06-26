#include "server.h"

server::server(unsigned short PORT){
    port = PORT;
    //listent for a new connection
    acceptor = make_shared <tcp::acceptor>(io_context_, tcp::endpoint(tcp::v4(), port));
    
    //socket creation 
    //socket_ = make_unique<tcp::socket>(io_context);
    //waiting for connection
    //acceptor->accept(*socket_);

    cout << "Servidor" << " incializado" << endl;
}

void server::async_accept(){
    auto self = shared_from_this();
    auto accept_handler = [this, self](const boost::system::error_code & ec, tcp::socket peer){  //cada nueva conexion necesita su propio socket
        if(!ec){
            cerr << "Conexión exitosa" << endl;
            shared_ptr<session> sess = make_shared<session>(move(peer), int(clients.size()+1)); 
            clients.push_back(move(sess)); 
            clients.back()->start_session();
        } 
        else cerr << "Error en la conexión" << endl;

        async_accept();
    };

    acceptor->async_accept(io_context_, accept_handler);
}


// void server::read_async() {
//     auto self = shared_from_this();  //se hace esto para que el objeto viva mientras se ejecuta la lectura o escritura
//     auto buffer= make_shared<boost::asio::streambuf>();
//     //string msg;
//     auto read_handler = [this, self, buffer](const boost::system::error_code& ec, size_t bytes_transferred) {
//         if (!ec){
//             cerr << "Recibido: " << bytes_transferred << " bytes\n";
//             string msg;
//             istream is(buffer.get());
//             getline(is, msg);
//             cerr << "recibido: " << msg << endl; 

//             read_async();
//         } 
//         else cerr << "Error: " << ec.message() << "\n";
        
//     };
    
//     boost::asio::async_read(*socket_, *buffer, boost::asio::transfer_at_least(1), read_handler);

//     //
//     //send_async(socket, "Recibido");
//     //que siga escuhando
//     //boost::asio::async_read_until(socket, buff, "\n" );
       
//     //return data;
// }


// void server::send_async(const string& message) {
//     auto self = shared_from_this();
//     auto buff = make_shared<string>(message);

//     auto write_handler = [this, self, buff](const boost::system::error_code &ec, size_t bytes_transferred){
//         if(!ec) cout << "Enviado:" << bytes_transferred << endl;
//         else cerr << "Error:" << ec.message() << endl;
//     };

//     boost::asio::async_write(*socket_, boost::asio::buffer(*buff), write_handler);
//     //read_async(socket);
// }

// void server::run(){
//     // while(true){
//     //     string message = read_(*socket_);
//     //     cout << message << endl;
//     //     send_(*socket_, "Hello From Server!");
//     //     cout << "Server sent Hello message to Client!" << endl;
//     // }
    
// }