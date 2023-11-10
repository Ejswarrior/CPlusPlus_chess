#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enums.h";
#include <iostream>

class ChessPieceBase
{

public: 
	sf::RectangleShape chessPiece;
	sf::Vector2f startingPosistion = sf::Vector2f(0,0);
	sf::Vector2f posistion = startingPosistion;
	float chessPieceHeight = 50;
	float chessPieceWidth = 100;
	bool isChessPieceActive = true;
	enum chessPieceTypes chessPieceType;


	void initializeChessPiece() {
		chessPiece.setSize(sf::Vector2f(chessPieceWidth, chessPieceHeight));
		chessPiece.setFillColor(sf::Color::Red);
		chessPiece.setPosition(posistion);
	}

	void move(sf::Vector2f newPosistion) {
		posistion = newPosistion;
		chessPiece.setPosition(newPosistion);
	}

	void takeChessPiece(sf::Vector2f currentPosiston, sf::Vector2f newPosistion, std::vector<class ChessPieceBase> chessPieceList) {
		for (class ChessPieceBase chessPiece : chessPieceList) {
			ChessPieceTypes king = king;
			if (chessPiece.chessPieceType == king) {
				std::cout << "You Won" << std::endl;
			}

			else if (chessPiece.posistion == newPosistion) {
				chessPiece.isChessPieceActive = false;
			}

			else if (chessPiece.posistion == currentPosiston) {
				chessPiece.move(newPosistion);
			}
		}
	}
	
	void canMoveToPositions() {

	}
};

