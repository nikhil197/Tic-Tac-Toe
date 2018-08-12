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
	do
	{
		row = std::rand() % playBoard.BOARD_SIZE;
		column = std::rand() % playBoard.BOARD_SIZE;
	} while (!playBoard.isEmpty(row, column));

	playBoard.setCellValue(row, column, this->m_Symbol);
}
