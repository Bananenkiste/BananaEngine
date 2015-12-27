#pragma once

#include <iostream>
#include <map>
#include "SDL_image.h"

class Loader
{
public:
	Loader();
	~Loader();

	static SDL_Surface* LoadImage(std::string);

private:

	static std::map<std::string, SDL_Surface*> surface;

};

