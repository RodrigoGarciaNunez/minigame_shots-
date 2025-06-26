#include "player.h"

player::player(int id, int life): id(id){
    cli = make_shared<client>(this->id); //debe ser compartido por el hilo que después lo usa
    pos = {10,20};
    move_(0, 0);      

    initscr();

}

void player::move_(int x, int y){
    
    pos= {pos.first+x, pos.second+y};
    cerr << pos.first << " "<<pos.second<< endl;

    string msg = to_string(pos.first)+","+to_string(pos.second);
    cli->send_async_messsage(msg);
    //cerr << "enviado " << msg << endl;

      
}

void player::shot(){

}

void player::end_game(){
    //endwin();  
}


void player::run_io(){
    cli->io.run();
}