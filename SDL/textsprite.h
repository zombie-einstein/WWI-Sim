// Create an SDL text sprite, inherets spritesheet properties,
// but adds ttf support and accepts string write text

#ifndef TEXTSPRITE_H
#define TEXTSPRITE_H

// Libraries
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

// Inheritance
#include <spriteSheet.h>


class textSprite : public spriteSheet{

    public:

        textSprite();

        // Use spriteSheet's destructor
        ~textSprite();

        //Creates image from text string
        bool loadFromRenderedText( std::string text, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font );

    protected:
    private:

};

#endif // TEXTSPRITE_H
