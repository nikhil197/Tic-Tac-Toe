#pragma once
#include <vector>

//Class representing the playing board
class Board
{
private:
	//2-D vector representing the playing board
	std::vector<std::vector<char>> *board;

public:
	//Board size
	const int BOARD_SIZE = 3;
	
	Board();

	~Board();

	//Reset the board
	void Reset();

	//Display the board
	void Display();

	//Check if there is any empty cell on the board
	bool IsMovePossible() const;

	//Check if the board has three 'symbols' in a row or a column or a diagonal
	bool CheckWinCondition(const char symbol) const;

	//To get the char at row and column indices on the board
	const char GetCellValue(int row, int column) const;

	//To set symbol at row and column indices on the board
	void SetCellValue(int row, int column, char symbol);

	//To check if the board is empty or not
	bool IsEmpty() const;

	//To check if the specified cell is empty on the board
	bool IsEmpty(int row, int column) const;
};

