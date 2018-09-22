#include "Game.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "Input.hpp"
#include "Loader.hpp"
#include "Settings.hpp"

Game::Game()
{
   SDL_Init(SDL_INIT_VIDEO);
   int flags = IMG_INIT_PNG;
   int inited = IMG_Init(flags);
   if (inited&flags != flags)
   {
	   std::cout << "SDL image init failed!" << std::endl;
   }
   
   Settings::LoadXML("Config/screens.xml");

   Input::Init();
   window = new Window();

}

Game::~Game()
{
    delete window;
	IMG_Quit();
    SDL_Quit();
}

void Game::GameLoop()
{
	std::cout << "Init Complete - Entering gameloop" << std::endl;
    SDL_Event event;
    while(!end)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
				case SDL_KEYUP: case SDL_KEYDOWN: case SDL_MOUSEMOTION: case SDL_MOUSEBUTTONUP: case SDL_MOUSEBUTTONDOWN:
					Input::Update(&event);
					break;
				case SDL_QUIT:
                    end = true;
                    break;
                default:
                    break;
            }
        }
		window->Update();
		window->Draw();
    }
}
