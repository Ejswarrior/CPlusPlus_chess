#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enums.h";
#include <iostream>

class ChessPieceBase
{

public:
	std::string id;
	sf::RectangleShape chessPiece;
	sf::Vector2f startingPosistion = sf::Vector2f(0,0);
	sf::Vector2f posistion = startingPosistion;
	float chessPieceHeight = 50;
	float chessPieceWidth = 100;
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight = 720 / 8;
	bool isChessPieceActive = true;
	enum chessPieceTypes chessPieceType;
	int player = 1;
	int	numberXPosition;
	int numberYPosition;

	void initializeChessPiece(std::string newId, sf::Vector2f newPosistion) {
		chessPiece.setSize(sf::Vector2f(chessPieceWidth, chessPieceHeight));
		chessPiece.setFillColor(sf::Color::Red);
		chessPiece.setPosition(newPosistion);
		id = newId;
	}

	void move(sf::Vector2f newPosistion) {
		posistion = newPosistion;
		chessPiece.setPosition(newPosistion);
	}

	void takeChessPiece(sf::Vector2f currentPosiston, sf::Vector2f newPosistion, std::vector<class ChessPieceBase> chessPieceList) {
		for (class ChessPieceBase chessPiece : chessPieceList) {
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

	sf::Vector2f distanceOfSquares(sf::Vector2f newPosistion) {
		int distanceY = std::ceil((newPosistion.y - posistion.y) / boardSquareHeight);
		int distanceX = std::ceil((newPosistion.x - posistion.x) / boardSquareWidth);

		return sf::Vector2f(distanceX, distanceY);
	}
};

