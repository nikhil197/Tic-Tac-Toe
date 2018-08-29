#include "Game.h"
#include "character/Bot.h"
#include "character/Player.h"

Game::Game(GameType gameType)
	:m_gameType(gameType)
{
	isOver = false;
	board = new Board();

	if (m_gameType == SINGLE_PLAYER)
	{
		player1 = new Bot("Bot", 'X', 'O', *board);
		player2 = new Player("Player", 'O', 'X', *board);
	}
	else
	{
		player1 = new Player("Player 1", 'X', 'O', *board);
		player2 = new Player("Player 2", 'O', 'X', *board);
	}

	currentPlayer = player1;
	isPlayer1Turn = true;
}

bool Game::IsMovePossible() const
{
	return board->IsMovePossible();
}

bool Game::CheckDraw()
{
	if (IsMovePossible())
		return false;

	if (!HasWon(player1->m_Symbol) && !HasWon(player2->m_Symbol))
		return isOver = true;

	return false;
}

bool Game::HasWon()
{
	return HasWon(currentPlayer->m_Symbol);
}

bool Game::HasWon(const char symbol)
{
	return isOver = board->CheckWinCondition(symbol);
}

bool Game::HasWon(const Character *player)
{
	return HasWon(player->m_Symbol);
}

void Game::RestartGame()
{
	//Reset the board
	board->Reset();

	currentPlayer = player1;
	isPlayer1Turn = true;

	isOver = false;
}

void Game::ChangeCurrentPlayer()
{
	isPlayer1Turn = !isPlayer1Turn;
	currentPlayer = isPlayer1Turn ? player1 : player2;
}

void Game::DisplayGameBoard() const
{
	board->Display();
}

Game::~Game()
{
	delete board;
	delete player1;
	delete player2;
}