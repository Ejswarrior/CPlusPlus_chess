#pragma once
#define STRUCT_HEADER
#include <SFML/Graphics.hpp>
#include "ChessPieceBase.h"
#include <vector>

struct boardSquareStruct {
	sf::RectangleShape boardSquare;
	int numberXPosition;
	int numberYPosistion;
	sf::Vector2f boardSquarePosistion;
	ChessPieceBase* chessPiece = nullptr;
	std::string chessPieceId;
};

struct selectedChessPieceStruct {
	ChessPieceBase* selectedChessPiece;
	bool isCurrentlySelected = false;
	sf::Vector2f selectedIndex;
	bool canDeleteSelected = false;
};