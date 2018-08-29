#include "Bot.h"
#include <iostream>

Bot::Bot(std::string name, char symbol, char oppSymbol, Board& board)
	:Character(name, symbol, oppSymbol, board)
{
}

Bot::~Bot()
{
}

void Bot::PerformAction() const
{
	if (this->playBoard.IsEmpty())
	{
		this->playBoard.SetCellValue(0, 0, this->m_Symbol);
		return;
	}

	int value = 0;
	std::pair<int, int> nextMove = GetNextOptimalMove(0, true, value);
	
	if (nextMove.first == -1 || nextMove.second == -1)
		return;

	playBoard.SetCellValue(nextMove.first, nextMove.second, this->m_Symbol);
}

int Bot::EvaluationFunction() const
{
	//Check if the bot has won
	if (playBoard.CheckWinCondition(this->m_Symbol))
		return rewardValue;

	//Check if the opponent has won
	else if (playBoard.CheckWinCondition(this->m_oppSymbol))
		return -rewardValue;

	//If non has won or its a draw
	else
		return 0;
}

std::pair<int, int> Bot::GetNextOptimalMove(int moves, bool botsTurn, int& value) const
{
	//BestValue will have the minimum or the maximum value (at the end) depending upon whether it is the opponent's turn or the bot's turn
	int bestValue = botsTurn ? INT_MIN : INT_MAX;

	//Get the value of the current board state
	int eval = EvaluationFunction();

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
			if(this->playBoard.GetCellValue(i, j) != '-')
				continue;

			//Set the current player's symbol on the board and set the value back to its initial value
			this->playBoard.SetCellValue(i, j, botsTurn ? this->m_Symbol : this->m_oppSymbol);
			value = tempValue;

			GetNextOptimalMove(moves + 1, !botsTurn, value);

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
			this->playBoard.SetCellValue(i, j, '-');
		}
	}
	value = bestValue;

	return nextMove;
}
