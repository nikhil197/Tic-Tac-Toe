#include "Player.h"

#include <iostream>

Player::Player(std::string name, char symbol, Board& board)
	:Character(name, symbol, board)
{
}

Player::~Player()
{
}

void Player::performAction() const
{
	int row, column;
	do 
	{
		std::cout << "\tEnter the row: ";
		std::cin >> row;

		std::cout << "\tEnter the column: ";
		std::cin >> column;
	} while (!playBoard.isEmpty(row - 1, column - 1));

	playBoard.setCellValue(row - 1, column - 1, this->m_Symbol);
}