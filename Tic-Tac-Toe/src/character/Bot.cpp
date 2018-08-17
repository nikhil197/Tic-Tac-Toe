#include "Bot.h"

Bot::Bot(std::string name, char symbol, Board& board)
	:Character(name, symbol, board)
{
}

Bot::~Bot()
{
}

void Bot::performAction() const
{
	int row, column;
	bool isCorrectInput = false;
	
	while(!isCorrectInput)
	{
		row = std::rand() % playBoard.BOARD_SIZE;
		column = std::rand() % playBoard.BOARD_SIZE;

		if (!playBoard.isEmpty(row, column))
			isCorrectInput = false;
		else
			isCorrectInput = true;
	}

	playBoard.setCellValue(row, column, this->m_Symbol);
}
