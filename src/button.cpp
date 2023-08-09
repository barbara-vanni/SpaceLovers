#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "button.hpp"
#include "graphics.hpp"
#include "entity.hpp"

Button::Button(int r, int g, int b, int x, int y, int width, int height, std::function<void()> onClick, char* message)
    : Entity(r, g, b, x, y, width, height),
    onClick(onClick), message(message)
{
    // Permet d'ajouter un nouveau bouton à la liste
    Graphics::buttons.insert(this);
    this -> text();
}

Button::~Button()
{
    // Permet de supprimer un bouton de la liste
    Graphics::buttons.erase(this);
}

void Button::text()
{
    TTF_Font* font =  TTF_OpenFont("Kichenset.otf", 10);
    SDL_Surface* text = TTF_RenderText_Blended(font, this -> message, (SDL_Color){255, 0, 0, 255});
    this -> texture = SDL_CreateTextureFromSurface(Graphics::renderer, text);
    SDL_FreeSurface(text);
}