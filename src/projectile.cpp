#include <SDL2/SDL.h>
#include "character.hpp"
#include "projectile.hpp"
#include "level.hpp"
#include "graphics.hpp"
#include "enemy.hpp"

Projectile::Projectile(int r, int g, int b, int x, int y, int direction)
	: Character(r, g, b, x, y, 5, 5, 1.0f),
	  direction(direction)

{
	Level::projectiles.insert(this);
}

Projectile::~Projectile()
{
	Level::projectiles.erase(this);
}

void Projectile::update()
{
	if (this->direction == 1)
		this->moveDown();
	else if (this->direction == -1)
		this->moveUp();

<<<<<<< HEAD
	if (SDL_HasIntersection(&this->rect, &Level::enemies->rect))
	{
		Level::enemies->takeDamage(1);
		this->~Projectile();
		return;
	}
=======
	// if (SDL_HasIntersection(&this->rect, &Level::player->rect))
	// {
	// 	Player::instance->takeDamage(1);
	// 	this->~Projectile();
	// 	return;
	// }
>>>>>>> 7cde139f6399d7c3c3fa8bb01ce1a57c2f7e6dc7

	if (this->rect.y > Graphics::screenHeight || this->rect.y < 0 || this->rect.x > Graphics::screenWidth || this->rect.x < 0)
	{
		this->~Projectile();
	}
}