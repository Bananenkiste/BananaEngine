#include "Loader.hpp"
#include "Window.hpp"

static std::map<std::string, SDL_Surface*>surface;

Loader::Loader()
{
}


Loader::~Loader()
{
}

SDL_Surface* Loader::LoadImage(std::string name)
{
	std::string path = "Image/" + name;
	//std::cout << Window::window << std::endl;
	/*if (Loader::surface.find("asdf") == Loader::surface.end())
	{*/
		SDL_Surface* tmp = IMG_Load(path.c_str());
		if (!tmp)
		{
			std::cout << "Image not found: " << path.c_str() << std::endl;
			return nullptr;
		}
		return tmp;
		//Loader::surface[name] = tmp;
		
	//}
	//return Loader::surface[name];
	//return nullptr;
}
