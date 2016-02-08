#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H


#include<SDL2/SDL.h>
#include <SDL_ttf.h>
#include <spriteSheet.h>


class textSprite : public spriteSheet
{
    public:

        // Use spriteSheet's destructor
        textSprite();

        ~textSprite();

        //Creates image from font string
        bool loadFromRenderedText( std::string text, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font );

    protected:
    private:
};

#endif // TEXTSPRITE_H
