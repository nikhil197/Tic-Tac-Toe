#include "Character.h"

Character::Character(std::string name, char symbol, char oppSymbol, Board& board)
	:m_Name(name), m_Symbol(symbol), playBoard(board), m_oppSymbol(oppSymbol)
{
}

Character::~Character()
{
}

