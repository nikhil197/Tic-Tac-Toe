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
		player1 = new Bot("Bot", 'X', *board);
		player2 = new Player("Player", 'O', *board);
	}
	else
	{
		player1 = new Player("Player 1", 'X', *board);
		player2 = new Player("Player 2", 'O', *board);
	}

	currentPlayer = player1;
	isPlayer1Turn = true;
}

bool Game::isMovePossible() const
{
	return board->isMovePossible();
}

bool Game::checkDraw()
{
	if (isMovePossible())
		return false;

	if (!hasWon(player1->m_Symbol) && !hasWon(player2->m_Symbol))
		return isOver = true;

	return false;
}

bool Game::hasWon()
{
	return hasWon(currentPlayer->m_Symbol);
}

bool Game::hasWon(const char symbol)
{
	return isOver = board->checkThreeConsecutive(symbol);
}

bool Game::hasWon(const Character *player)
{
	return hasWon(player->m_Symbol);
}

void Game::restartGame()
{
	//Reset the board
	board->reset();

	isOver = false;
}

void Game::changeCurrentPlayer()
{
	isPlayer1Turn = !isPlayer1Turn;
	currentPlayer = isPlayer1Turn ? player1 : player2;
}

void Game::displayGameBoard() const
{
	board->display();
}

Game::~Game()
{
	delete board;
	delete player1;
	delete player2;
}