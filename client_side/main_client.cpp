//#include "client.h"
#include "player.h"
#include <iostream>
#include <locale.h>

using std::stoi;
using std::cerr;
using std::to_string;

int main(int argc, char * argv[]){
    int id;
    //cerr << "🤠" << endl;
    cbreak();               // Deshabilita el buffering de línea
    noecho();  
    //keypad(stdscr, TRUE);   // Permite teclas especiales (flechas, etc.)
    nodelay(stdscr, TRUE);  // 🔥 getch() no bloqueará
    //setlocale(LC_ALL, "");

    if(argc < 2){
        cerr << "sintaxis incorrecta (./client_shots id)" << endl;
        return 0;
    } 
        
    try{
        id = stoi(argv[1]);
    }
    catch(...){
        cerr << "ID inválida" << endl;
        return 0;
    }

    bool game_over = false;
    char input='l';
    shared_ptr<player> ply = make_shared<player>(id);
    
    thread io_thread([ply](){
        ply->run_io();
    });

    //printw("*");
    while(!game_over){
        input = getch();
        cerr << input ;
        switch (input)
        {
        case 'w':
        case 'W':
            ply->move_(0, 1);
            break;
        case 's':    
        case 'S':
            ply->move_(0, -1);
            break;
        
        case 'a':
        case 'A':
            ply->move_(-1, 0);
            break;
        
        case 'd':
        case 'D':
            ply->move_(1, 0);
            break;
        
        case 'q':
        case 'Q':
            ply->end_game();
            game_over =true;
            break;
        }
    }   
    // shared_ptr<client> cli = make_shared<client>(id);
    //
    
    
    // string message = "Hola server, soy" +to_string(id);
    // cerr << message << endl;
    
    // cli->send_async_messsage(message);

    io_thread.join();
    //cli->io.run(); 
    return 0;
}