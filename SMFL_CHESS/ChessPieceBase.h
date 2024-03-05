#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enums.h";
#include <iostream>

class ChessPieceBase
{

public:
	std::string id;
	sf::Texture texture;
	sf::Sprite chessPiece;
	sf::Vector2f startingPosistion = sf::Vector2f(0,0);
	sf::Vector2f posistion = startingPosistion;
	float chessPieceHeight = 100;
	float chessPieceWidth = 150;
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight = 720 / 8;
	int player;
	bool isChessPieceActive = true;
	enum chessPieceTypes chessPieceType;
	int	numberXPosition;
	int numberYPosition;

	virtual bool canMovePosistions(const sf::Vector2f newPosistion, const boardSquareStruct boardSquareStruct)  = 0;


	void initializeChessPiece(std::string newId, sf::Vector2f newPosistion, std::string assetName, int playerType ) {
		texture.loadFromFile(assetName);
		chessPiece.setTexture(texture);
		chessPiece.setScale(sf::Vector2f(chessPieceWidth/chessPiece.getLocalBounds().width, chessPieceHeight/chessPiece.getLocalBounds().height));
		chessPiece.setPosition(newPosistion);
		sf::Vector2f scale = chessPiece.getScale();
		std::cout << scale.x << std::endl;
		player = playerType;
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

