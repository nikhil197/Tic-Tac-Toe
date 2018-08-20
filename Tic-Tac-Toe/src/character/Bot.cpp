#include "Bot.h"
#include <iostream>

Bot::Bot(std::string name, char symbol, char oppSymbol, Board& board)
	:Character(name, symbol, oppSymbol, board)
{
}

Bot::~Bot()
{
}

void Bot::performAction() const
{
	if (this->playBoard.isEmpty())
	{
		this->playBoard.setCellValue(0, 0, this->m_Symbol);
		return;
	}

	int value = 0;
	std::pair<int, int> nextMove = getNextOptimalMove(0, true, value);
	
	if (nextMove.first == -1 || nextMove.second == -1)
		return;

	playBoard.setCellValue(nextMove.first, nextMove.second, this->m_Symbol);
}

int Bot::evaluationFunction() const
{
	//Check if the bot has won
	if (playBoard.checkWinCondition(this->m_Symbol))
		return rewardValue;

	//Check if the opponent has won
	else if (playBoard.checkWinCondition(this->m_oppSymbol))
		return -rewardValue;

	//If non has won or its a draw
	else
		return 0;
}

std::pair<int, int> Bot::getNextOptimalMove(int moves, bool botsTurn, int& value) const
{
	//BestValue will have the minimum or the maximum value (at the end) depending upon whether it is the opponent's turn or the bot's turn
	int bestValue = botsTurn ? INT_MIN : INT_MAX;

	//Get the value of the current board state
	int eval = evaluationFunction();

	//If bot has won, return the boardValue - moves used to get there
	if (eval > 0)
	{
		value = eval - moves;
		return std::pair<int, int>(-1, -1);
	}
	//If the opponent has won, return the boardValue + moves used to get there
	else if(eval < 0)
	{
		value = eval + moves;
		return std::pair<int, int>(-1, -1);
	}

	//Store the initial value passed
	int tempValue = value;

	//Stores the best move for the bot
	std::pair<int, int> nextMove;

	//Check all the possible moves
	for (int i = 0; i < this->playBoard.BOARD_SIZE; i++)
	{
		for (int j = 0; j < this->playBoard.BOARD_SIZE; j++)
		{
			if(this->playBoard.getCellValue(i, j) != '-')
				continue;

			//Set the current player's symbol on the board and set the value back to its initial value
			this->playBoard.setCellValue(i, j, botsTurn ? this->m_Symbol : this->m_oppSymbol);
			value = tempValue;

			getNextOptimalMove(moves + 1, !botsTurn, value);

			//If it is opponent's turn and the value after the above move is less than the bestValue (Because the opponent is the minimizer)
			if (!botsTurn && value < bestValue)
			{
				bestValue = value;
				nextMove.first = i;
				nextMove.second = j;
			}

			//If it is bot's turn and the value after the above move is more than the bestValue (Because the bot is the maximizer)
			if (botsTurn && value > bestValue)
			{
				bestValue = value;
				nextMove.first = i;
				nextMove.second = j;
			}

			//Remove the above from the board
			this->playBoard.setCellValue(i, j, '-');
		}
	}
	value = bestValue;

	return nextMove;
}
