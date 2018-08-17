#include <iostream>

#include "Board.h"

Board::Board()
{
	board = new std::vector<std::vector<char>>(BOARD_SIZE, std::vector<char>(BOARD_SIZE, '-'));
}

void Board::reset()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::vector<char> *row = &board->at(i);
		for (int j = 0; j < BOARD_SIZE; j++)
			row->at(j) = '-';
	}
}

void Board::display()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << "\t";
		std::vector<char> *row = &board->at(i);
		for (int j = 0; j < BOARD_SIZE; j++)
			std::cout << row->at(j) << " ";
		std::cout << std::endl;
	}
}

const char Board::getCellValue(int row, int column) const
{
	return (*board)[row][column];
}

void Board::setCellValue(int row, int column, char symbol)
{
	board->at(row).at(column) = symbol;
}

bool Board::isMovePossible() const
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (board->at(i).at(j) == '-')
				return true;

	return false;
}

bool Board::checkThreeConsecutive(const char symbol) const
{
	//Check rows
	for (int i = 0; i < BOARD_SIZE; i++)
		if ((*board)[i][0] == symbol && (*board)[i][1] == symbol && (*board)[i][2] == symbol)
			return true;

	//Check columns
	for (int i = 0; i < BOARD_SIZE; i++)
		if ((*board)[0][i] == symbol && (*board)[1][i] == symbol && (*board)[2][i] == symbol)
			return true;

	//Check Diagonals
	if ((*board)[0][0] == symbol && (*board)[1][1] == symbol && (*board)[2][2] == symbol)
		return true;

	if ((*board)[0][2] == symbol && (*board)[1][1] == symbol && (*board)[2][0] == symbol)
		return true;

	//If no row / column / diagonal has the same character in all three places
	return false;
}

bool Board::isEmpty(int row, int column) const
{
	return board->at(row).at(column) == '-' ? true : false;
}

Board::~Board()
{
	delete board;
}
