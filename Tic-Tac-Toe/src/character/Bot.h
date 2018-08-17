#pragma once
#include "Character.h"

//Class representing a bot
class Bot :
	public Character
{
public:
	Bot(std::string name, char symbol, Board& board);
	
	~Bot();

	//To perform the Action of a bot
	void performAction() const override;
};

