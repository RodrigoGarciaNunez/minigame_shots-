#include "server.h"

using std::cerr;

int main(int argc, char * argv[]){
    shared_ptr<server> serv = make_shared<server>();
    
    serv->async_accept();
    
    thread io_thread([serv](){
        serv->io_context_.run();
    });

    

    io_thread.join();    
    //serv->run(); 
    return 0;
}