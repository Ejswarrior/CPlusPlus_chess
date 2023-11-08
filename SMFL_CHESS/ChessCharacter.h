#pragma once
#include <SFML/Graphics.hpp>

class ChessCharacter
{

public: 
	sf::Vector2f posistion = sf::Vector2f(0,0);
	sf::RectangleShape chessPiece;
	float chessPieceHeight = 50;
	float chessPieceWidth = 100;

	void initializeChessPiece() {
		chessPiece.setSize(sf::Vector2f(chessPieceWidth, chessPieceHeight));
		chessPiece.setFillColor(sf::Color::Red);
		chessPiece.setPosition(posistion);
	}

	void move(sf::Vector2f newPosistion) {
		chessPiece.setPosition(newPosistion);
	}
};

