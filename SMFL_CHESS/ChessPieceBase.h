#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "BoardSquareStruct.h"
#include "ChessPieceMoves.h"
class ChessPieceBase
{
private: 
	

public:
	std::string id = "";
	sf::Vector2f startingPosistion = sf::Vector2f(0, 0);
	std::string assetName = "";
	int player = 1;
	std::string chessPieceType = "";

	ChessPieceBase(std::string id,
		sf::Vector2f startingPosistion,
		std::string assetName,
		int player = 1,
		std::string chessPieceType = "") {
		id = id;
		startingPosistion = sf::Vector2f(startingPosistion.x, startingPosistion.y + 75);  // We add 75 to move eveything down
		assetName = assetName;
		player = player;
		chessPieceType = chessPieceType;

		texture.loadFromFile(assetName);
		baseChessPiece.setTexture(texture);
		baseChessPiece.setScale(sf::Vector2f(chessPieceWidth / baseChessPiece.getLocalBounds().width, chessPieceHeight / baseChessPiece.getLocalBounds().height));
		baseChessPiece.setPosition(startingPosistion);
		sf::Vector2f scale = baseChessPiece.getScale();
	}
	
	sf::Vector2f posistion = startingPosistion;
	sf::Texture texture;
	sf::Sprite baseChessPiece;

	float chessPieceHeight = 100;
	float chessPieceWidth = 150;
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight = 720 / 8;
	bool isChessPieceActive = true;
	int	numberXPosition = 0;
	int numberYPosition = 0;
	bool pawnHasReachedEnd;
	int boardSquareIndex = 0;
	
	virtual bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType, std::vector<boardSquareStruct> boardSquareAttributes) {
		std::cout << "hit base" << std::endl;
		return false;
	};

	void move(sf::Vector2f newPosistion, sf::Vector2f gridPositions, bool didReachEnd, int newXposition, int newYposition) {
		posistion = newPosistion;


		if (chessPieceType == "Pawn") {
			//TODO: Need to create UI to promote pawn to another chess piece
			if (player == 1 && gridPositions.y == 8  || player == 2 && gridPositions.y == 1 ) {
				didReachEnd = true;
				pawnHasReachedEnd = true;
			}
		}
		numberXPosition = newXposition;
		numberYPosition = newYposition;
		baseChessPiece.setPosition(newPosistion);
	}


	sf::Vector2f distanceOfSquares(sf::Vector2f newPosistion) {
		int distanceY = std::ceil((newPosistion.y - posistion.y) / boardSquareHeight);
		int distanceX = std::ceil((newPosistion.x - posistion.x) / boardSquareWidth);



		return sf::Vector2f(distanceX, distanceY);
	}
};

