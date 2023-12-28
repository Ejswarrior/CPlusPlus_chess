#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "ChessPieceBase.h"
#include "Pawn.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	ChessPieceBase chessPiece;
	std::vector<class ChessCharacter>;
	window.setFramerateLimit(60);
	chessPiece.initializeChessPiece();
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight =  720 / 8;
	std::vector<sf::RectangleShape> boardSquares;
	int xPosistion = 0;
	int yPosistion = 0;
	Pawn pawn;
	pawn.initializeChessPiece();


	for (int i = 0; i <= 64; ++i) {
		sf::RectangleShape boardSquare;

		if (i == 0) {
			boardSquare.setPosition(sf::Vector2f(0, 0));
		}

		else if (i % 8 == 0) {
			yPosistion += boardSquareHeight;
			xPosistion = 0;
			boardSquare.setPosition(sf::Vector2f(0, yPosistion));
		}
		else if(i % 8 > 0)  {
			xPosistion += boardSquareWidth;
			boardSquare.setPosition(sf::Vector2f(xPosistion, yPosistion));
		}

		boardSquare.setSize(sf::Vector2f(boardSquareWidth, boardSquareHeight));
		if (i % 2  == 0 && yPosistion/boardSquareHeight % 2 == 0) boardSquare.setFillColor(sf::Color::Black);
		else if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquare.setFillColor(sf::Color::White);
		else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquare.setFillColor(sf::Color::White);
		else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquare.setFillColor(sf::Color::Black);

		else  boardSquare.setFillColor(sf::Color::White);

		boardSquares.push_back(boardSquare);
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
					for (sf::RectangleShape boardSquare : boardSquares) {
						sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								pawn.distanceOfSquares(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2), 
									boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								if (pawn.canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y))) {
									std::cout << "Hit Here" << std::endl;
									pawn.move(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2), boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								}
							}
					}
				}
			}
		
		}

			window.clear();
			for (sf::RectangleShape boardSquare : boardSquares) {
				window.draw(boardSquare);
			}
			window.draw(pawn.chessPiece);
			window.display();
	}

	return 0;
}