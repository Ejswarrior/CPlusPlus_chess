#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "struct_header.h"
#include "ChessPieceBase.h"
#include "Pawn.h" 
#include "Rook.h"
template <typename T>
void logger(T message) {
	std::cout << message << std::endl;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	std::vector<class ChessCharacter>;
	window.setFramerateLimit(60);
	const int boardSquareWidth = 1280 / 8;
	const int boardSquareHeight =  720 / 8;
	const float chessPieceHeight = 100;
	const float chessPieceWidth = 150;

	std::vector<sf::RectangleShape> boardSquares;
	std::vector<boardSquareStruct> boardSquareAttributes;
	bool initialized = false;
	bool hasPawnReachedEnd = false;
	int xPosistion = 0;
	int yPosistion = 0;

	int xPosistionCount = 1;
	int yPoisitionCount = 1;
	ChessPieceBase* pawn = new Pawn();
	ChessPieceBase* pawn2 = new Pawn();
	ChessPieceBase* rook1 = new Rook();
	pawn->initializeChessPiece("pawnTest1", sf::Vector2f(0, 0), "images/player1Pawn.png", 1, "Pawn");
	pawn2->initializeChessPiece("pawnTest2", sf::Vector2f(boardSquareWidth , boardSquareHeight * 7), "images/player2Pawn.png", 2, "Pawn");
	rook1->initializeChessPiece("rookTest1", sf::Vector2f(boardSquareWidth * 2, 0), "images/player1Rook.png", 1, "Rook");
	selectedChessPieceStruct currentlySelectedChessPiece;
	

	if (!initialized) {
		for (int i = 0; i <= 64; i++) {

			boardSquareStruct boardSquareStruct;
			if (i == 0) {
				boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, 0));
				boardSquareStruct.boardSquarePosistion = sf::Vector2f(0, 0);
				boardSquareStruct.numberXPosition = 1;
				boardSquareStruct.numberYPosistion = 1;
				pawn->numberXPosition = 1;
				pawn->numberYPosition = 1;
				boardSquareStruct.chessPiece = pawn;
				boardSquareStruct.chessPieceId = pawn->id;
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
				if (i == 57) {
					boardSquareStruct.chessPiece = pawn2;
					boardSquareStruct.chessPieceId = pawn2->id;
					pawn2->numberYPosition = 8;
					pawn2->numberXPosition = 2;
				}
				if (i == 2) {
					boardSquareStruct.chessPiece = rook1;
					boardSquareStruct.chessPieceId = rook1->id;
					rook1->numberYPosition = 1;
					rook1->numberXPosition = 3;
				}

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
						logger("hit select");

						for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								if (currentBoardSquareStruct.chessPiece != nullptr) {
							
									currentlySelectedChessPiece.selectedChessPiece = currentBoardSquareStruct.chessPiece;

									currentlySelectedChessPiece.isCurrentlySelected = true;
									currentlySelectedChessPiece.selectedIndex = sf::Vector2f(currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion);
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
		
								if (currentlySelectedChessPiece.selectedChessPiece->canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y), currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion, 1)) {
									//if (currentBoardSquareStruct.chessPiece != nullptr && currentlySelectedChessPiece.selectedChessPiece->player == currentBoardSquareStruct.chessPiece->player) continue;
									if (currentBoardSquareStruct.chessPiece != nullptr &&  currentBoardSquareStruct.chessPiece != currentlySelectedChessPiece.selectedChessPiece && currentlySelectedChessPiece.selectedChessPiece->player != currentBoardSquareStruct.chessPiece->player) {
										currentBoardSquareStruct.chessPiece->isChessPieceActive = false;
									}
									currentBoardSquareStruct.chessPiece = currentlySelectedChessPiece.selectedChessPiece;
									currentBoardSquareStruct.chessPiece->numberXPosition = currentBoardSquareStruct.numberXPosition;
									currentBoardSquareStruct.chessPiece->numberYPosition = currentBoardSquareStruct.numberYPosistion;
									currentBoardSquareStruct.chessPieceId = currentBoardSquareStruct.chessPiece->id;


									sf::Vector2f moveCoordinates = sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (chessPieceWidth / 2), boardSquarePosistion.y + (boardSquareHeight / 2) - (chessPieceHeight / 2));
									currentlySelectedChessPiece.selectedChessPiece->move(moveCoordinates, sf::Vector2f(currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion), hasPawnReachedEnd);
									currentlySelectedChessPiece.isCurrentlySelected = false;
									currentlySelectedChessPiece.selectedChessPiece = nullptr;
									currentlySelectedChessPiece.canDeleteSelected = true;

								}

								else {
									currentlySelectedChessPiece.isCurrentlySelected = false;
									continue;
								}
							}
						}

						//Need to find old index and remove references to original chess piece position

						if(currentlySelectedChessPiece.canDeleteSelected && currentlySelectedChessPiece.selectedIndex.x != 0 && currentlySelectedChessPiece.selectedIndex.y != 0)
						for (boardSquareStruct& embeddedBoardSquareStruct : boardSquareAttributes) {
							if (embeddedBoardSquareStruct.chessPiece != nullptr && embeddedBoardSquareStruct.numberXPosition == currentlySelectedChessPiece.selectedIndex.x && embeddedBoardSquareStruct.numberYPosistion == currentlySelectedChessPiece.selectedIndex.y) {
								embeddedBoardSquareStruct.chessPiece = nullptr;
								embeddedBoardSquareStruct.chessPieceId = "";
								currentlySelectedChessPiece.selectedIndex = sf::Vector2f(0, 0);
								currentlySelectedChessPiece.canDeleteSelected = false;
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
			if(pawn->isChessPieceActive) window.draw(pawn->baseChessPiece);
			if(pawn2->isChessPieceActive) window.draw(pawn2->baseChessPiece);
			if (rook1->isChessPieceActive) window.draw(rook1->baseChessPiece);
			window.display();
	}

	return 0;
}