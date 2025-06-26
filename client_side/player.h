#include "client.h"
#include <utility>
#include <ncurses.h> //para no usar consola directamente

using std::pair;
using std::get;
using std::to_string;

class player{
public:
    player(int id, int life = 3);
    void move_(int x, int y);
    void run_io();
    void shot();
    void end_game();

private:
   

    int life;
    int id;
    pair<float, float> pos;
    shared_ptr<client>  cli;
};