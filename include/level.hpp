#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SDL2/SDL.h>
#include <set>
#include <string>

#include "enemy.hpp"
#include "projectile.hpp"
#include "text.hpp"
#include "inGameItem.hpp"

class Level
{
public:
	Level();
	~Level();
	static std::set<Projectile *> projectiles;
	static std::set<Enemy *> enemies;
	static std::set<Enemy *> bosses;
	static std::set<InGameItem *> powerUps;
	static Level *instance;
	long long int nanoSecond;
	int currentLvl;
	float difficulty;
	std::string count;
	Text *timer;
	Text *levelRunning;
	Text *xpTotal;
	void update();
	void countdown();

	unsigned long long int timeSinceLastSpawn;
	unsigned long long int timeSinceLastPoweUp;
	unsigned long long int timeSinceLastBoss;
};

#endif