#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

#include "Game.h"


int main()
{
	bool quit = false;
	bool newGame = true;

	while (!quit)
	{
		Game *game = nullptr;
	
		//Game type selection
		std::cout << std::endl << std::endl;
		std::cout << "\tWelcome to Tic-Tac-Toe" << std::endl;
		std::cout << "\tSelect game Type: " << std::endl;
		std::cout << "\t1. Single Player (Play against a bot)." << std::endl;
		std::cout << "\t2. Two Players (Play against another player)." << std::endl;
		std::cout << "\t";
		short choice;
		std::cin >> choice;

		//Set game type
		GameType gameType;
		if (choice == 1)
			gameType = SINGLE_PLAYER;
		else
			gameType = MULTI_PLAYER;

		game = new Game(gameType);
		
		if (game == nullptr)
		{
			std::cout << "\t Oops!! Something went wrong. Restarting the game." << std::endl;
			continue;
		}

		while (!game->isGameOver())
		{
			if (game->checkDraw())
			{
				std::cout << "\tGame was a draw" << std::endl;
				break;
			}

			std::cout << "\t" + game->getCurrentPlayer()->m_Name + "\'s turn" << std::endl;

			//Complete the current player's move
			game->getCurrentPlayer()->performAction();

			std::cout << std::endl;

			//Display the game board
			game->displayGameBoard();

			//Check if the current player has won
			if (game->hasWon())
				std::cout << "\t Game Over !!!! " + game->getCurrentPlayer()->m_Name + " won the game. " << std::endl;

			std::cout << std::endl << std::endl;

			game->changeCurrentPlayer();

			//Ask the user if he wants to quit 
			if (game->isGameOver())
			{
				//clear the input buffer
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

				std::cout << "\tPress N to start a new game or R to restart the current game or Q to quit." << std::endl;
				std::cout << "\t";
				char endChoice;
				std::cin.get(endChoice);

				//Reset the board for a new game
				if (endChoice == 'R')
				{
					std::cout << "\t Restarting the current game." << std::endl;
					game->restartGame();
					Sleep(2000);
					system("CLS");
				}
				else if (endChoice == 'N')
				{
					std::cout << "\tStarting a new game." << std::endl;
					Sleep(2000);
					system("CLS");
				}
				else
				{
					std::cout << "\tThank you for playing Tic-Tac-Toe. " << std::endl;
					Sleep(3000);
					quit = true;
				}
			}
		}
		
		delete game;
	}

	std::cin.get();
	return 0;
}