#include "client.h"
#include <iostream>

using std::stoi;

int main(int argc, char * argv[]){
    int id;
    try{
        id = stoi(argv[1]);
    }
    catch(...){
        cerr << "Entrada inválida" << endl;
        return 0;
    }
    cerr <<id <<endl;
    unique_ptr<client> cli = make_unique<client>(id);
    cli->run(); 
    return 0;
}