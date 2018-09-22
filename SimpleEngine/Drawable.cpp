#include "Drawable.hpp"
#include "Loader.hpp"

Drawable::Drawable()
{
    //ctor
}

Drawable::~Drawable()
{
    //dtor
}

void Drawable::Draw(SDL_Surface* screen)
{

}

void Drawable::Update()
{

}

SDL_Rect *Drawable::NewRect(int x, int y, int w, int h)
{
	SDL_Rect* nrect = new SDL_Rect();
	nrect->x = x;
	nrect->y = y;
	nrect->w = w;
	nrect->h = h;
	return nrect;
}

