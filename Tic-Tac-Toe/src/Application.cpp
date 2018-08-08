#include <iostream>
#include <limits>

const int BOARD_SIZE = 3;

const char PLAYER_SYMBOL = 'O';
const char BOT_SYMBOL = 'X';

char board[BOARD_SIZE][BOARD_SIZE];

//To check if there is a cell empty on the board
bool isEmpty()
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
			if (board[i][j] == '-')
				return true;
	return false;
}

//To check if the specified cell is empty on the board
bool isEmpty(int row, int column)
{
	return board[row][column] == '-' ? true : false;
}

//To check if a player has won
bool checkWin(const char& character)
{
	//Check rows
	for (int i = 0; i < BOARD_SIZE; i++)
		if (board[i][0] == character && board[i][1] == character && board[i][2] == character)
			return true;

	//Check columns
	for (int i = 0; i < BOARD_SIZE; i++)
		if (board[0][i] == character && board[1][i] == character && board[2][i] == character)
			return true;

	//Check Diagonals
	if (board[0][0] == character && board[1][1] == character && board[2][2] == character)
		return true;

	if (board[0][2] == character && board[1][1] == character && board[2][0] == character)
		return true;

	//If no row / column / diagonal has the same character in all three places
	return false;
}

//To check if the game is a draw
bool checkDraw()
{
	//If there is a space available on the board
	if (isEmpty())
		return false;
	else if (!checkWin(PLAYER_SYMBOL) && !checkWin(BOT_SYMBOL))
		return true;
	return false;
}

//To process the player move
void playerMove()
{

	std::cout << "Enter the row number: ";
	int row;
	std::cin >> row;
	int column;
	std::cout << "Enter the column number: ";
	std::cin >> column;
	board[row - 1][column - 1] = PLAYER_SYMBOL;

}

//To process the Bot move
void botMove()
{
	int row, column;
	do
	{
		row = std::rand() % BOARD_SIZE;
		column = std::rand() % BOARD_SIZE;
	} while (!isEmpty(row, column));

	board[row][column] = BOT_SYMBOL;

	return;
}

//Display the current board state
void display()
{
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++)
			std::cout << (char)board[i][j] << ' ';
		std::cout << std::endl;
	}
}

//Initialize the game board
void init()
{
	std::memset(board, '-', BOARD_SIZE * BOARD_SIZE);
}

int main()
{
	bool isRunning = true;
	bool isBotsTurn = true;

	init();

	while (isRunning)
	{
		if (checkDraw())
		{
			std::cout << "Game was a draw" << std::endl;
			isRunning = false;
		}

		isBotsTurn ? botMove() : playerMove();

		if (isBotsTurn)
		{
			if (checkWin(BOT_SYMBOL))
			{
				//print a message
				std::cout << "Oops!! Looks like the Bot pulled ahead." << std::endl;
				isRunning = false;
			}
		}
		else
		{
			if (checkWin(PLAYER_SYMBOL)) {
				std::cout << "Congratulations!! You have won the game" << std::endl;
				isRunning = false;
			}
		}

		display();
		std::cout << std::endl << std::endl;
		isBotsTurn = !isBotsTurn;

		//Ask the user if he wants to quit 
		if (!isRunning)
		{
			//clear the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "Press N to start a new game or Q to quit." << std::endl;
			char choice;
			std::cin.get(choice);

			//Reset the board for a new game
			if (choice == 'N')
			{
				isRunning = true;
				isBotsTurn = true;
				init();
				system("CLS");
			}
		}
	}

	std::cin.get();
	return 0;
}