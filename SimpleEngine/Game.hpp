#ifndef GAME_H
#define GAME_H

#include "Window.hpp"

class Game
{
    public:
        Game();
        virtual ~Game();
        void GameLoop();
    protected:
    private:
        bool end = false;
        Window* window;
};

#endif // GAME_H
