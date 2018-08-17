#include "Character.h"

Character::Character(std::string name, char symbol, Board& board)
	:m_Name(name), m_Symbol(symbol), playBoard(board)
{
}

Character::~Character()
{
}

