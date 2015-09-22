// SimpleEngine.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//


#include <stdio.h>
#include <iostream>
#include "Game.hpp"


int main(int argc, char* argv[])
{
    Game* g = new Game();

    g->GameLoop();

    delete g;
    return 0;
}


