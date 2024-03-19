#pragma once
#define STRUCT_HEADER
#include <SFML/Graphics.hpp>
#include "ChessPieceBase.h"
#include <vector>

// Used for global values like structs templates and for now some global functions

struct boardSquareStruct {
	sf::RectangleShape boardSquare;
	int numberXPosition;
	int numberYPosistion;
	sf::Vector2f boardSquarePosistion;
	ChessPieceBase* chessPiece = nullptr;
	std::string chessPieceId;
};

struct playerHasWonStruct {
	bool isKingTaken = false;
	int* whichPlayerWon = nullptr;
};

struct selectedChessPieceStruct {
	ChessPieceBase* selectedChessPiece;
	bool isCurrentlySelected = false;
	sf::Vector2f selectedIndex;
	bool canDeleteSelected = false;
	sf::Color selectedDefaultColor;
};

template <typename T>
void logger(T message) {
	std::cout << message << std::endl;
}