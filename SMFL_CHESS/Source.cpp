#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include "struct_header.h"
#include "ChessPieceBase.h"
#include "Pawn.h" 
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	std::vector<class ChessCharacter>;
	window.setFramerateLimit(60);
	const int boardSquareWidth = 1280 / 8;
	const int boardSquareHeight =  720 / 8;
	const float chessPieceHeight = 100;
	const float chessPieceWidth = 150;
	const sf::Color defaultBoardSquareDark = sf::Color{ 68,45,14 };
	const sf::Color defaultBoardSquareLight = sf::Color{ 229,193,146 };
	const sf::Color selectedBoardSquareColor = sf::Color{ 224,212,116 };
	std::vector<sf::RectangleShape> boardSquares;
	std::vector<boardSquareStruct> boardSquareAttributes;
	bool initialized = false;
	bool hasPawnReachedEnd = false;

	int xPosistion = 0;
	int yPosistion = 0;
	int xPosistionCount = 1;
	int yPoisitionCount = 1;

	//Todo: Find a better way to initialize all the Chess pieces
	ChessPieceBase* pawn = new Pawn();
	ChessPieceBase* pawn2 = new Pawn();
	ChessPieceBase* rook1 = new Rook();
	ChessPieceBase* bishop1 = new Bishop();
	ChessPieceBase* knight1 = new Knight();
	pawn->initializeChessPiece("pawnTest1", sf::Vector2f(0, 0), "images/player1Pawn.png", 1, "Pawn");
	pawn2->initializeChessPiece("pawnTest2", sf::Vector2f(boardSquareWidth , boardSquareHeight * 7), "images/player2Pawn.png", 2, "Pawn");
	rook1->initializeChessPiece("rookTest1", sf::Vector2f(boardSquareWidth * 2, 0), "images/player1Rook.png", 1, "Rook");
	bishop1->initializeChessPiece("bishopTest1", sf::Vector2f(boardSquareWidth * 4, 0), "images/player1Bishop.png", 1, "Bishop");
	knight1->initializeChessPiece("knightTest1", sf::Vector2f(boardSquareWidth * 6, 0), "images/knightPlayer1.svg.png", 1, "Knight");

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
				if (i == 4) {
					boardSquareStruct.chessPiece = bishop1;
					boardSquareStruct.chessPieceId = bishop1->id;
					bishop1->numberYPosition = 1;
					bishop1->numberXPosition = 5;
				}
				if (i == 6) {
					boardSquareStruct.chessPiece = knight1;
					boardSquareStruct.chessPieceId = knight1->id;
					knight1->numberYPosition = 1;
					knight1->numberXPosition = 7;
				}

				boardSquareStruct.numberXPosition = xPosistionCount + 1;
				xPosistionCount += 1;
				xPosistion += boardSquareWidth;
				boardSquareStruct.numberYPosistion = yPoisitionCount;
				boardSquareStruct.boardSquare.setPosition(sf::Vector2f(xPosistion, yPosistion));
				boardSquareStruct.boardSquarePosistion = sf::Vector2f(xPosistion, yPosistion);
			}
			boardSquareStruct.boardSquare.setSize(sf::Vector2f(boardSquareWidth, boardSquareHeight));
			if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 == 0 || i % 2 > 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquareStruct.boardSquare.setFillColor(defaultBoardSquareDark);
			else if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 > 0 || i % 2 > 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(defaultBoardSquareLight);

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
					//Select the Chess Piece
					if (!currentlySelectedChessPiece.isCurrentlySelected) {
						for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								if (currentBoardSquareStruct.chessPiece != nullptr) {
									currentlySelectedChessPiece.selectedDefaultColor = currentBoardSquareStruct.boardSquare.getFillColor();
									currentBoardSquareStruct.boardSquare.setFillColor(sf::Color{ 224,212,116 });
									currentlySelectedChessPiece.selectedChessPiece = currentBoardSquareStruct.chessPiece;
									currentlySelectedChessPiece.isCurrentlySelected = true;
									currentlySelectedChessPiece.selectedIndex = sf::Vector2f(currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion);
								}
							}
						}
					}
					//Move Chess Piece
					else {
						for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							//Check for mouse position compared to boardSquare
							if (event.mouseButton.x > boardSquarePosistion.x && event.mouseButton.x < boardSquarePosistion.x + boardSquareWidth
								&& event.mouseButton.y > boardSquarePosistion.y && event.mouseButton.y < boardSquarePosistion.y + boardSquareHeight) {
								
								//Check if we can move from the Chess Piece derived class
								if (currentlySelectedChessPiece.selectedChessPiece->canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y), 
									currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion, 1)) {
									//Check if we try to take our own chess piece
									if (currentBoardSquareStruct.chessPiece != nullptr && currentlySelectedChessPiece.selectedChessPiece->player == currentBoardSquareStruct.chessPiece->player) {
										currentlySelectedChessPiece.selectedChessPiece = nullptr;
										currentlySelectedChessPiece.isCurrentlySelected = false;
										continue;
									}

									//Check if we take other players chess piece
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
								// If we can't move remove selected Chess Piece
								else {
									currentlySelectedChessPiece.isCurrentlySelected = false;
									continue;
								}
							}
						}

						//Need to find old index and remove references to original chess piece position

						if (currentlySelectedChessPiece.canDeleteSelected && currentlySelectedChessPiece.selectedIndex.x != 0 && currentlySelectedChessPiece.selectedIndex.y != 0)
							for (int i = 0; i < boardSquareAttributes.size(); ++i) {
								boardSquareStruct& embeddedBoardSquareStruct = boardSquareAttributes.at(i);
								if (embeddedBoardSquareStruct.chessPiece != nullptr && embeddedBoardSquareStruct.numberXPosition == currentlySelectedChessPiece.selectedIndex.x && embeddedBoardSquareStruct.numberYPosistion == currentlySelectedChessPiece.selectedIndex.y) {
									embeddedBoardSquareStruct.chessPiece = nullptr;
									embeddedBoardSquareStruct.chessPieceId = "";
									embeddedBoardSquareStruct.boardSquare.setFillColor(currentlySelectedChessPiece.selectedDefaultColor);
									currentlySelectedChessPiece.selectedIndex = sf::Vector2f(0, 0);
									currentlySelectedChessPiece.canDeleteSelected = false;
								}
							};
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
			if (bishop1->isChessPieceActive) window.draw(bishop1->baseChessPiece);
			if (knight1->isChessPieceActive) window.draw(knight1->baseChessPiece);
			window.display();
	}

	return 0;
}