#include "Window.hpp"

Window::Window()
{
    window = SDL_CreateWindow(
        "A cool Game",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
		SDL_WINDOW_SHOWN                   // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        std::cout<<"Could not create window: %s\n"<< SDL_GetError()<<std::endl;
    }
	screen = SDL_GetWindowSurface(window);
	scene = new Scene();
}

Window::~Window()
{
	SDL_FreeSurface(screen);
    SDL_DestroyWindow(window);
	delete scene;
}


void Window::Update()
{
	scene->Update();
}

void Window::Draw()
{
	scene->Draw(screen);
	SDL_UpdateWindowSurface(window);
}
