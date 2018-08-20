#pragma once
#include "Character.h"

//Class representing a bot
class Bot :
	public Character
{
public:
	Bot(std::string name, char symbol, char oppSymbol, Board& board);
	
	~Bot();

	//To perform the Action of a bot
	void performAction() const override;

private:
	const int rewardValue = 10;

	//Evaluate the given board state to find the next optimal move
	int evaluationFunction() const;

	//Get the next optimal move
	std::pair<int, int> getNextOptimalMove(int moves, bool botsTurn, int& value) const;
};

