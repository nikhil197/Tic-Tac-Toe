#pragma once
#include "Board.h"
#include "character/Character.h"

//Type of the game
enum GameType
{
	SINGLE_PLAYER = 0,
	MULTI_PLAYER
};

//Class representing the game
class Game
{
private:
	//Board representing the game
	Board *board;
	
	//First player of the game
	Character *player1;

	//Second player of the game
	Character *player2;

	//Player who's turn it is
	const Character *currentPlayer;

	//Whether the game is over or not
	bool isOver;

	//Is it player1's turn or player2's
	bool isPlayer1Turn;

	//Current Game type
	GameType m_gameType;

public:
	Game(GameType gameType);
	
	~Game();

	//Returns Whether a move is possible or not
	bool isMovePossible() const;

	//Returns Whether the game is over or not
	bool isGameOver() const { return isOver; }

	//Returns whether the game is drawn
	bool checkDraw();

	//Returns whether the current player has won
	bool hasWon();

	//Returns whether player with 'symbol' has won
	bool hasWon(const char symbol);

	//Returns whether the player has won
	bool hasWon(const Character *player);

	//Restart the game
	void restartGame();

	//Change the player whose turn it is
	void changeCurrentPlayer();

	//Get the player whose turn turn it is
	const Character* getCurrentPlayer() const { return currentPlayer; };

	void displayGameBoard() const;
};

