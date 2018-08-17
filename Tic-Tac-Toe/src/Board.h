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
	static const int BOARD_SIZE = 3;
	
	Board();

	~Board();

	//Reset the board
	void reset();

	//Display the board
	void display();

	//Check if there is any empty cell on the board
	bool isMovePossible() const;

	//Check if the board has three 'symbols' in a row or a column or a diagonal
	bool checkThreeConsecutive(const char symbol) const;

	//To get the char at row - 1 and column - 1 indices on the board
	const char getCellValue(int row, int column) const;

	//To set symbol at row - 1 and column -1 indices on the board
	void setCellValue(int row, int column, char symbol);

	//To check if the specified cell is empty on the board
	bool isEmpty(int row, int column) const;
};

