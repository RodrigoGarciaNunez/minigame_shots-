#include "client.h"

class player{
public:
    player(int id, int life = 3);

private:
    void move();
    void shot();

    int life;
    int id;
    client * cli;
};