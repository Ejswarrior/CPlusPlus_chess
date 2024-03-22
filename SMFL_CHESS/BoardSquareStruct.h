#pragma once
#define BOARDSQUARESTRUCT
#include <SFML/Graphics.hpp>

struct boardSquareStruct {
	sf::RectangleShape boardSquare;
	int numberXPosition;
	int numberYPosistion;
	sf::Vector2f boardSquarePosistion;
	std::string chessPieceId;
};