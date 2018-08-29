#pragma once
#include "Game.h"

//Game resource managing class
class GameManager
{
private:
	//A pointer to the game object
	Game* gameObj;

public:
	explicit GameManager(Game *gameObj);
	~GameManager();

	//Get access to the raw resource
	Game* operator->();

	//Check Equality
	bool operator==(Game *otherObj);
};

