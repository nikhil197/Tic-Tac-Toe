#include <iostream>
#include <string>
#include <limits>
#include <Windows.h>

#include "Game.h"
#include "GameManager.h"

#define LOG(x) std::cout << x << std::endl;

int main()
{
	bool quit = false;

	while (!quit)
	{	
		//Game type selection
		LOG("\n");
		LOG("\tWelcome to Tic-Tac-Toe");
		LOG("\tSelect game Type: ");
		LOG("\t1. Single Player (Play against a bot).");
		LOG("\t2. Two Players (Play against another player).");
		LOG("\t3. Quit");
		std::cout << "\t";
		short choice;
		std::cin >> choice;

		//Set game type
		GameType gameType;
		if (choice == 1)
			gameType = SINGLE_PLAYER;
		else if(choice == 2)
			gameType = MULTI_PLAYER;
		else if (choice == 3)
		{
			quit = true;
			continue;
		}

		GameManager game(new Game(gameType));
		
		if (game == nullptr)
		{
			LOG("\t Oops!! Something went wrong. Restarting the game.");
			continue;
		}

		while (!game->IsGameOver())
		{
			LOG("\t" + game->GetCurrentPlayer()->m_Name + "\'s turn");

			std::cout << std::endl;

			//Complete the current player's move
			game->GetCurrentPlayer()->PerformAction();

			//Display the game board
			game->DisplayGameBoard();

			//Check if the current player has won
			if (game->HasWon())
			{
				LOG("\t Game Over !!!! " + game->GetCurrentPlayer()->m_Name + " won the game. ");
			}
			else if (game->CheckDraw())
			{
				LOG("\tGame was a draw");
			}

			std::cout << std::endl;

			game->ChangeCurrentPlayer();

			//Ask the user if he wants to quit 
			if (game->IsGameOver())
			{
				//clear the input buffer
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

				LOG("\tPress N to start a new game or R to restart the current game or Q to quit.");
				std::cout << "\t";
				char endChoice;
				std::cin.get(endChoice);

				//Reset the board for a new game
				if (endChoice == 'R' || endChoice == 'r')
				{
					LOG("\t Restarting the current game.");
					game->RestartGame();
					Sleep(2000);
					system("CLS");
				}
				else if (endChoice == 'N' || endChoice == 'n')
				{
					LOG("\tStarting a new game.");
					Sleep(2000);
					system("CLS");
				}
				else if(endChoice == 'Q' || endChoice == 'q')
				{
					LOG("\tThank you for playing Tic-Tac-Toe. ");
					Sleep(3000);
					quit = true;
				}
			}
		}
	}

	std::cin.get();
	return 0;
}