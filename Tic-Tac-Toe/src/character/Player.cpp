#include "Player.h"

#include <iostream>

Player::Player(std::string name, char symbol, char oppSymbol, Board& board)
	:Character(name, symbol, oppSymbol, board)
{
}

Player::~Player()
{
}

void Player::performAction() const
{
	int row, column;
	bool isCorrectInput = false;

	while(!isCorrectInput)
	{
		std::cout << "\tEnter the row: ";
		std::cin >> row;

		std::cout << "\tEnter the column: ";
		std::cin >> column;

		if (!playBoard.isEmpty(row - 1, column - 1))
			std::cout << "\tInvalid values!! Please enter the row and column values again." << std::endl << std::endl;
		else
			isCorrectInput = true;
	}

	playBoard.setCellValue(row - 1, column - 1, this->m_Symbol);
}