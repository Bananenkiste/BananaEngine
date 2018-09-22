#pragma once
#include "SDL_image.h"
#include "Button.hpp"
#include <iostream>
#include <vector>

class Scene
{
public:
	Scene(std::string);
	~Scene();

	void Update();
	void Draw(SDL_Surface* screen);

	std::vector<Drawable*> drawables = std::vector<Drawable*>();

private:
	

};

