#pragma once
#include "character/Character.h"

//Class representing the user controlled character
class Player :
	public Character
{
public:
	Player(std::string name, char symbol, Board& board);
	
	~Player();

	//To perform the player action
	void performAction() const override;
};

