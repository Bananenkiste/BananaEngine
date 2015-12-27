#pragma once

#include "SDL_image.h"
#include "Button.hpp"

class Scene
{
public:
	Scene();
	~Scene();

	void Update();
	void Draw(SDL_Surface* screen);

private:
	Button* btn;

};

