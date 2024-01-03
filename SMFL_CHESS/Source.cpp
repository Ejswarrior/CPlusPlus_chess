#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "ChessPieceBase.h"
#include "Pawn.h"

int main() {
	struct boardSquareStruct {
		sf::RectangleShape boardSquare;
		int numberXPosition;
		int numberYPosistion;
		sf::Vector2f boardSquarePosistion;
	};
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	ChessPieceBase chessPiece;
	std::vector<class ChessCharacter>;
	window.setFramerateLimit(60);
	chessPiece.initializeChessPiece();
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight =  720 / 8;
	std::vector<sf::RectangleShape> boardSquares;
	std::vector<boardSquareStruct> boardSquareAttributes;
	
	int xPosistion = 0;
	int yPosistion = 0;
	Pawn pawn;
	pawn.initializeChessPiece();
	int xPosistionCount = 1;
	int yPoisitionCount = 1;

	for (int i = 0; i <= 64; ++i) {
		boardSquareStruct boardSquareStruct;

		if (i == 0) {
			boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, 0));
			boardSquareStruct.boardSquarePosistion = sf::Vector2f(0, 0);
			boardSquareStruct.numberXPosition = 1;
			boardSquareStruct.numberYPosistion = 1;
		}

		else if (i % 8 == 0) {
			yPosistion += boardSquareHeight;
			boardSquareStruct.numberXPosition = 1;
			xPosistionCount = 1;
			yPoisitionCount += 1;
			boardSquareStruct.numberYPosistion = yPoisitionCount;
			xPosistion = 0;
			boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, yPosistion));
			boardSquareStruct.boardSquarePosistion = sf::Vector2f(0, yPosistion);
		}

		else {
			boardSquareStruct.numberXPosition = xPosistionCount + 1;
			xPosistionCount += 1;
			xPosistion += boardSquareWidth;
			boardSquareStruct.numberYPosistion = yPoisitionCount;
			boardSquareStruct.boardSquare.setPosition(sf::Vector2f(xPosistion, yPosistion));
			boardSquareStruct.boardSquarePosistion = sf::Vector2f(xPosistion, yPosistion);
		}
		boardSquareStruct.boardSquare.setSize(sf::Vector2f(boardSquareWidth, boardSquareHeight));
		if (i % 2  == 0 && yPosistion/boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(sf::Color::Black);
		else if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquareStruct.boardSquare.setFillColor(sf::Color::White);
		else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(sf::Color::White);
		else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 > 0)boardSquareStruct.boardSquare.setFillColor(sf::Color::Black);

		else boardSquareStruct.boardSquare.setFillColor(sf::Color::White);

		boardSquareAttributes.push_back(boardSquareStruct);
	}
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();

			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left) 
				{	
					for (boardSquareStruct boardSquareStruct : boardSquareAttributes) {
						sf::RectangleShape boardSquare = boardSquareStruct.boardSquare;
						sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								std::cout << boardSquareStruct.numberYPosistion << std::endl;
								pawn.distanceOfSquares(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2), 
									boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								if (pawn.canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y))) {
									pawn.move(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2), boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								}
							}
					}
				}
			}		
		}

			window.clear();
			for (boardSquareStruct boardSquareStruct : boardSquareAttributes) {
				window.draw(boardSquareStruct.boardSquare);
			}
			window.draw(pawn.chessPiece);
			window.display();
	}

	return 0;
}