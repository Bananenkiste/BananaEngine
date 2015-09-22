#include "Game.hpp"
#include "SDL2/SDL.h"


Game::Game()
{
   SDL_Init(SDL_INIT_VIDEO);
   window = new Window();
}

Game::~Game()
{
    delete window;
    SDL_Quit();
}

void Game::GameLoop()
{
    SDL_Event event;
    while(!end)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    end = true;
                    break;
                default:
                    break;
            }
        }
    }
}
