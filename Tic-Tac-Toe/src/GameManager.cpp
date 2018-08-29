#include "GameManager.h"

GameManager::GameManager(Game *gameObj)
{
	this->gameObj = gameObj;
}

GameManager::~GameManager()
{
	delete gameObj;
}

Game* GameManager::operator->()
{
	return gameObj;
}

bool GameManager::operator==(Game *otherObj)
{
	return (gameObj == otherObj);
}