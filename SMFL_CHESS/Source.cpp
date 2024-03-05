#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "ChessPieceBase.h"
#include "Pawn.h" 
#include "struct_header.h"


std::vector<boardSquareStruct> intializeBoard(int boardSquareHeight, int boardSquareWidth,  ChessPieceBase pawn, ChessPieceBase pawn2, std::vector<boardSquareStruct> boardSquareAttributes) {
	int xPosistion = 0;
	int yPosistion = 0;

	int xPosistionCount = 1;
	int yPoisitionCount = 1;


	std::vector<boardSquareStruct> intialBoardVector;
	for (int i = 0; i <= 64; i++) {

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
		if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(sf::Color{ 68,45,14 });
		else if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquareStruct.boardSquare.setFillColor(sf::Color{ 229,193,146 });
		else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(sf::Color{ 229,193,146 });
		else if (i % 2 > 0 && yPosistion / boardSquareHeight % 2 > 0)boardSquareStruct.boardSquare.setFillColor(sf::Color{ 68,45,14 });

		else boardSquareStruct.boardSquare.setFillColor(sf::Color::White);

		intialBoardVector.push_back(boardSquareStruct);
	}

	return intialBoardVector;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	ChessPieceBase chessPiece;
	std::vector<class ChessCharacter>;
	window.setFramerateLimit(60);
	int boardSquareWidth = 1280 / 8;
	int boardSquareHeight =  720 / 8;
	std::vector<sf::RectangleShape> boardSquares;
	std::vector<boardSquareStruct> boardSquareAttributes;
	bool initialized = false;

	Pawn pawn;
	Pawn pawn2;
	pawn.initializeChessPiece("pawnTest1", sf::Vector2f(0, 0), "images/Chess_plt45.png", 1);
	pawn2.initializeChessPiece("pawnTest2", sf::Vector2f(boardSquareWidth , boardSquareHeight), "images/Chess_plt45.png", 2);

	struct selectedChessPieceStruct {
		ChessPieceBase selectedChessPiece;
		bool isCurrentlySelected = false;
	};
	selectedChessPieceStruct currentlySelectedChessPiece;
	

	if (!initialized) {
		boardSquareAttributes = intializeBoard(boardSquareHeight, boardSquareWidth, pawn, pawn2, boardSquareAttributes);
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
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight && currentBoardSquareStruct.chessPiece != nullptr) {
								currentBoardSquareStruct.chessPiece->distanceOfSquares(sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (pawn.chessPieceWidth / 2),
									boardSquarePosistion.y + (boardSquareHeight / 2) - (pawn.chessPieceHeight / 2)));
								if(currentBoardSquareStruct.chessPiece != nullptr) std::cout << currentBoardSquareStruct.chessPiece->id << std::endl;
								if (currentBoardSquareStruct.chessPiece->canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y), currentBoardSquareStruct)) {
									if ( currentBoardSquareStruct.chessPiece->id != currentlySelectedChessPiece.selectedChessPiece.id) {
										currentBoardSquareStruct.chessPiece->isChessPieceActive = false;
									}
									currentBoardSquareStruct.chessPiece = &currentlySelectedChessPiece.selectedChessPiece;
									currentlySelectedChessPiece.isCurrentlySelected = false;
									pawn.numberXPosition = currentBoardSquareStruct.numberXPosition;
									pawn.numberYPosition = currentBoardSquareStruct.numberYPosistion;
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
			if(pawn.isChessPieceActive) window.draw(pawn.chessPiece);
			if(pawn2.isChessPieceActive) window.draw(pawn2.chessPiece);
			window.display();
	}

	return 0;
}