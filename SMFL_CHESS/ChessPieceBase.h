#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class ChessPieceBase
{
private: 
	

public:
	std::string id = "";
	sf::Vector2f startingPosistion = sf::Vector2f(0, 0);
	std::string assetName = "";
	int player = 1;
	std::string chessPieceType = "";

	ChessPieceBase(std::string id = "",
		sf::Vector2f startingPosistion = sf::Vector2f(0, 0),
		std::string assetName = "",
		int player = 1,
		std::string chessPieceType = "Pawn") {
		id = id;
		startingPosistion = startingPosistion;
		assetName = assetName;
		player = player;
		chessPieceType = chessPieceType;
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
	
	  virtual bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType) {
		std::cout << "hit base" << std::endl;
		return false;
	};

	void initializeChessPiece(std::string newId, sf::Vector2f newPosistion, std::string assetName, int playerType, std::string chessType ) {
		texture.loadFromFile(assetName);
		baseChessPiece.setTexture(texture);
		baseChessPiece.setScale(sf::Vector2f(chessPieceWidth/ baseChessPiece.getLocalBounds().width, chessPieceHeight/ baseChessPiece.getLocalBounds().height));
		baseChessPiece.setPosition(newPosistion);
		sf::Vector2f scale = baseChessPiece.getScale();
		std::cout << scale.x << std::endl;
		player = playerType;
		id = newId;
		chessPieceType = chessType;
	}

	void move(sf::Vector2f newPosistion, sf::Vector2f gridPositions, bool didReachEnd) {
		posistion = newPosistion;


		if (chessPieceType == "Pawn") {
			//TODO: Need to create UI to promote pawn to another chess piece
			if (player == 1 && gridPositions.y == 8  || player == 2 && gridPositions.y == 1 ) {
				std::cout << "Pawn has reached end" << std::endl;
			}
		}

		baseChessPiece.setPosition(newPosistion);
	}


	sf::Vector2f distanceOfSquares(sf::Vector2f newPosistion) {
		int distanceY = std::ceil((newPosistion.y - posistion.y) / boardSquareHeight);
		int distanceX = std::ceil((newPosistion.x - posistion.x) / boardSquareWidth);

		return sf::Vector2f(distanceX, distanceY);
	}
};

