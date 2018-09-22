#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "SDL.h"
#include "SDL_rect.h"

class Drawable
{
    public:
        Drawable();
        virtual ~Drawable();

        virtual void Draw(SDL_Surface*);
		virtual void Update();

		SDL_Rect *NewRect(int, int, int, int);
    protected:
    private:
};

#endif // DRAWABLE_H
