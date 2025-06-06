#include "client.h"

int main(int argc, char * argv[]){
    client * cli = new client(3333);
    cli->run(); 
    return 0;
}