#include "Scene.hpp"
#include "Settings.hpp"

Scene::Scene(std::string screen)
{
	std::cout << "Loading Scene: " << screen << std::endl;
	ScreenData* data = Settings::GetSceneData(screen);
	if (data != NULL)
	{
		for (std::vector<ButtonData>::iterator it = data->buttons.begin(); it != data->buttons.end(); ++it)
		{
			Button* btn = new Button(&(*it));
			drawables.insert(drawables.end(), btn);
			std::cout << "Creating Button: " << (*it).title  << std::endl;
		}
	}
}


Scene::~Scene()
{
	drawables.clear();
}

void Scene::Update()
{
	for (std::vector<Drawable*>::iterator it = drawables.begin(); it != drawables.end(); ++it)
	{
		(*it)->Update();
	}
}

void Scene::Draw(SDL_Surface* screen)
{
	for (std::vector<Drawable*>::iterator it = drawables.begin(); it != drawables.end(); ++it)
	{
		(*it)->Draw(screen);
	}
}
