#include "server.h"

int main(int argc, char * argv[]){
    server * ser = new server(3333);
    ser->run(); 
    return 0;
}