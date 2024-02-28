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
		ChessPieceBase* chessPiece = nullptr;
	};
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	ChessPieceBase chessPiece;
	std::vector<class ChessCharacter>;
	window.setFramerateLimit(60);
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight =  720 / 8;
	std::vector<sf::RectangleShape> boardSquares;
	std::vector<boardSquareStruct> boardSquareAttributes;
	bool initialized = false;
	
	int xPosistion = 0;
	int yPosistion = 0;
	Pawn pawn;
	Pawn pawn2;
	pawn.initializeChessPiece("pawnTest1", sf::Vector2f(0, 0));
	pawn2.initializeChessPiece("pawnTest2", sf::Vector2f(0, boardSquareHeight));
	int xPosistionCount = 1;
	int yPoisitionCount = 1;
	struct selectedChessPieceStruct {
		ChessPieceBase selectedChessPiece;
		bool isCurrentlySelected = false;
	};
	selectedChessPieceStruct currentlySelectedChessPiece;
	

	if (!initialized) {

		for (int i = 0; i <= 64; i++) {
			std::cout << i << std::endl;

			boardSquareStruct boardSquareStruct;
			if (i == 0) {
				boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, 0));
				boardSquareStruct.boardSquarePosistion = sf::Vector2f(0, 0);
				boardSquareStruct.numberXPosition = 1;
				boardSquareStruct.numberYPosistion = 1;
				pawn.numberXPosition = 1;
				pawn.numberYPosition = 1;
				boardSquareStruct.chessPiece = &pawn;
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
				if (i == 9) boardSquareStruct.chessPiece = &pawn2;
				boardSquareStruct.numberXPosition = xPosistionCount + 1;
				xPosistionCount += 1;
				xPosistion += boardSquareWidth;
				boardSquareStruct.numberYPosistion = yPoisitionCount;
				boardSquareStruct.boardSquare.setPosition(sf::Vector2f(xPosistion, yPosistion));
				boardSquareStruct.boardSquarePosistion = sf::Vector2f(xPosistion, yPosistion);
			}
			boardSquareStruct.boardSquare.setSize(sf::Vector2f(boardSquareWidth, boardSquareHeight));
			if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(sf::Color::Black);
			else if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquareStruct.boardSquare.setFillColor(sf::Color::White);
			else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(sf::Color::White);
			else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 > 0)boardSquareStruct.boardSquare.setFillColor(sf::Color::Black);

			else boardSquareStruct.boardSquare.setFillColor(sf::Color::White);

			boardSquareAttributes.push_back(boardSquareStruct);
		}
	}

	initialized = true;

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

					if (!currentlySelectedChessPiece.isCurrentlySelected) {
						for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								if (currentBoardSquareStruct.chessPiece != nullptr) {
									currentlySelectedChessPiece.selectedChessPiece = *currentBoardSquareStruct.chessPiece;
									currentlySelectedChessPiece.isCurrentlySelected = true;
									std::cout << currentlySelectedChessPiece.selectedChessPiece.id << std::endl;
								}
							}
						}
					}
					else {
						for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								pawn.distanceOfSquares(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2),
									boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								if(currentBoardSquareStruct.chessPiece != nullptr) std::cout << currentBoardSquareStruct.chessPiece->id << std::endl;
								if (pawn.canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y))) {
									std::cout << currentBoardSquareStruct.numberXPosition << std::endl;
									std::cout << currentBoardSquareStruct.numberYPosistion << std::endl;
									currentBoardSquareStruct.chessPiece = &pawn;
									currentlySelectedChessPiece.isCurrentlySelected = false;
									std::cout << currentlySelectedChessPiece.selectedChessPiece.id << std::endl;
									for (boardSquareStruct& embeddedBoardSquareStruct : boardSquareAttributes) {
										if (currentBoardSquareStruct.numberXPosition != embeddedBoardSquareStruct.numberXPosition || currentBoardSquareStruct.numberYPosistion != embeddedBoardSquareStruct.numberYPosistion && embeddedBoardSquareStruct.chessPiece == &pawn) {
											embeddedBoardSquareStruct.chessPiece = nullptr;
										}
									}

									pawn.move(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2), boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								}
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
			window.draw(pawn2.chessPiece);
			window.display();
	}

	return 0;
}