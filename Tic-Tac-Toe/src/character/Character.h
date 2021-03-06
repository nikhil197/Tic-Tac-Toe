#pragma once
#include <string>
#include "Board.h"

//Class representing a player in the game
class Character
{
public:
	//Name of the character
	const std::string m_Name;

	//Symbol played by the character
	const char m_Symbol;

	//Symbol played by the opponent
	const char m_oppSymbol;

	//Board on which the character is playing
	Board& playBoard;

public:
	Character(std::string name, char symbol, char oppSymbol, Board& board);
	
	virtual ~Character();

	//To perform the character action
	virtual void PerformAction() const = 0;
};

