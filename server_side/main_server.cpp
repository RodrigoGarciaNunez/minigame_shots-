#include "server.h"

int main(int argc, char * argv[]){
    unique_ptr<server> ser = make_unique<server>();
    ser->run(); 
    return 0;
}