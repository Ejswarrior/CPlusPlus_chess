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
#include "Queen.h"
#include "King.h"


void setChessPieceBoardSquareAttributes(boardSquareStruct &boardSquare, ChessPieceBase* chessPiece, int numberXPosition, int numberYPosition) {
	boardSquare.chessPieceId = chessPiece->id;
	chessPiece->numberYPosition = numberYPosition;
	chessPiece->numberXPosition = numberXPosition;
}


int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "My First Window");
	window.setFramerateLimit(60);
	const int boardSquareWidth = 1280 / 8;
	const int boardSquareHeight = 720 / 8;
	const float chessPieceHeight = 100;
	const float chessPieceWidth = 150;
	const sf::Color defaultBoardSquareDark = sf::Color{ 68,45,14 };
	const sf::Color defaultBoardSquareLight = sf::Color{ 229,193,146 };
	const sf::Color selectedBoardSquareColor = sf::Color{ 224,212,116 };
	std::vector<sf::RectangleShape> boardSquares;
	std::vector<boardSquareStruct> boardSquareAttributes;
	playerHasWonStruct hasAPlayerWon;
	bool initialized = false;
	bool hasPawnReachedEnd = false;

	int xPosistion = 0;
	int yPosistion = 0;
	int xPosistionCount = 1;
	int yPoisitionCount = 1;

	
	//Todo: Find a better way to initialize all the Chess pieces

	ChessPieceBase* player1Pawn1 = new Pawn("player1Pawn1", sf::Vector2f(0, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn2 = new Pawn("player1Pawn2", sf::Vector2f(boardSquareWidth, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn3 = new Pawn("player1Pawn3", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn4 = new Pawn();
	ChessPieceBase* player1Pawn5 = new Pawn();
	ChessPieceBase* player1Pawn6 = new Pawn();
	ChessPieceBase* player1Pawn7 = new Pawn();
	ChessPieceBase* player1Pawn8 = new Pawn();
	ChessPieceBase* player2Pawn1 = new Pawn();
	ChessPieceBase* player2Pawn2 = new Pawn();
	ChessPieceBase* player2Pawn3 = new Pawn();
	ChessPieceBase* player2Pawn4 = new Pawn();
	ChessPieceBase* player2Pawn5 = new Pawn();
	ChessPieceBase* player2Pawn6 = new Pawn();
	ChessPieceBase* player2Pawn7 = new Pawn();
	ChessPieceBase* player2Pawn8 = new Pawn();

	ChessPieceBase* pawn2 = new Pawn();
	ChessPieceBase* player1Rook1 = new Rook();
	ChessPieceBase* player1Rook2 = new Rook();

	ChessPieceBase* bishop1 = new Bishop();
	ChessPieceBase* player1Knight1 = new Knight();
	ChessPieceBase* player1Knight2 = new Knight();
	ChessPieceBase* player1Bishop1 = new Bishop();
	ChessPieceBase* player1Bishop2 = new Bishop();
	ChessPieceBase* player1Queen = new Queen();

	ChessPieceBase* player1King = new King();

	player1Pawn1->initializeChessPiece("player1Pawn1", sf::Vector2f(0, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn2->initializeChessPiece("player1Pawn2", sf::Vector2f(boardSquareWidth, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn3->initializeChessPiece("player1Pawn3", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn4->initializeChessPiece("player1Pawn4", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn5->initializeChessPiece("player1Pawn5", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn6->initializeChessPiece("player1Pawn6", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn7->initializeChessPiece("player1Pawn7", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player1Pawn8->initializeChessPiece("player1Pawn8", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	player2Pawn1->initializeChessPiece("player2Pawn1", sf::Vector2f(boardSquareWidth, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn2->initializeChessPiece("player2Pawn2", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn3->initializeChessPiece("player2Pawn3", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn4->initializeChessPiece("player2Pawn4", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn5->initializeChessPiece("player2Pawn5", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn6->initializeChessPiece("player2Pawn6", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn7->initializeChessPiece("player2Pawn7", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player2Pawn8->initializeChessPiece("player2Pawn8", sf::Vector2f(boardSquareWidth * 8, boardSquareHeight * 6), "images/player1Pawn.png", 2, "Pawn");
	player1Rook1->initializeChessPiece("player1Rook1", sf::Vector2f(0, 0), "images/player1Rook.png", 1, "Rook");
	player1Rook2->initializeChessPiece("player1Rook2", sf::Vector2f(boardSquareWidth * 7, 0), "images/player1Rook.png", 1, "Rook");
	player1Knight1->initializeChessPiece("player1Knight1", sf::Vector2f(boardSquareWidth, 0), "images/knightPlayer1.svg.png", 1, "Knight");
	player1Knight2->initializeChessPiece("player1Knight2", sf::Vector2f(boardSquareWidth * 6, 0), "images/knightPlayer1.svg.png", 1, "Knight");
	player1Bishop1->initializeChessPiece("player1Bishop1", sf::Vector2f(boardSquareWidth * 2, 0), "images/player1Bishop.png", 1, "Bishop");
	player1Bishop2->initializeChessPiece("player1Bishop2", sf::Vector2f(boardSquareWidth * 5, 0), "images/player1Bishop.png", 1, "Bishop");
	player1Queen->initializeChessPiece("player1Queen", sf::Vector2f(boardSquareWidth * 3, 0), "images/queenPlayer1.svg.png", 1, "Queen");
	player1King->initializeChessPiece("player1King", sf::Vector2f(boardSquareWidth * 4, 0), "images/kingPlayer1.svg.png", 1, "King");

	selectedChessPieceStruct currentlySelectedChessPiece;
	

	if (!initialized) {
		for (int i = 0; i <= 64; i++) {

			boardSquareStruct boardSquareStruct;
			if (i == 0) {
				boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, 0));
				boardSquareStruct.boardSquarePosistion = sf::Vector2f(0, 0);
				boardSquareStruct.numberXPosition = 1;
				boardSquareStruct.numberYPosistion = 1;
			/*	boardSquareStruct.chessPiece = player1Rook1;
				boardSquareStruct.chessPieceId = player1Rook1->id;
				player1Rook1->numberYPosition = 1;
				player1Rook1->numberXPosition = 1;*/
				setChessPieceBoardSquareAttributes(boardSquareStruct, player1Rook1, 1, 1);
		
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
				if (i == 8) {
					boardSquareStruct.chessPieceId = player1Pawn1->id;
					player1Pawn1->numberYPosition = 2;
					player1Pawn1->numberXPosition = 1;
				}
			}

			else {
				if (i == 7) {
				
					setChessPieceBoardSquareAttributes(boardSquareStruct, player1Rook2, 1, 7);
				}
			
				if (i == 9) {
					boardSquareStruct.chessPieceId = player1Pawn2->id;
					player1Pawn2->numberYPosition = 2;
					player1Pawn2->numberXPosition = 2;
				}
				if (i == 10) {
					boardSquareStruct.chessPieceId = player1Pawn3->id;
					player1Pawn3->numberYPosition = 2;
					player1Pawn3->numberXPosition = 3;
				}
				if (i == 11) {
					boardSquareStruct.chessPieceId = player1Pawn4->id;
					player1Pawn4->numberYPosition = 2;
					player1Pawn4->numberXPosition = 3;
				}
				if (i == 12) {
					boardSquareStruct.chessPieceId = player1Pawn5->id;
					player1Pawn5->numberYPosition = 2;
					player1Pawn5->numberXPosition = 4;
				}
				if (i == 13) {
					boardSquareStruct.chessPieceId = player1Pawn6->id;
					player1Pawn6->numberYPosition = 2;
					player1Pawn6->numberXPosition = 5;
				}
				if (i == 14) {
					boardSquareStruct.chessPieceId = player1Pawn7->id;
					player1Pawn7->numberYPosition = 2;
					player1Pawn7->numberXPosition = 6;
				}
				if (i == 15) {
					boardSquareStruct.chessPieceId = player1Pawn8->id;
					player1Pawn8->numberYPosition = 2;
					player1Pawn8->numberXPosition = 8;
				}
			
				if (i == 4) {
					boardSquareStruct.chessPieceId = bishop1->id;
					bishop1->numberYPosition = 1;
					bishop1->numberXPosition = 5;
				}
				
				if (i == 1) {
					setChessPieceBoardSquareAttributes(boardSquareStruct, player1Knight1, 2, 1);
				}

				if (i == 6) setChessPieceBoardSquareAttributes(boardSquareStruct, player1Knight2, 7, 1);
				if (i == 2) setChessPieceBoardSquareAttributes(boardSquareStruct, player1Bishop1, 3, 1);
				if (i == 5)setChessPieceBoardSquareAttributes(boardSquareStruct, player1Bishop2, 6, 1);
				if (i == 3) setChessPieceBoardSquareAttributes(boardSquareStruct, player1Queen, 4, 1);
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

	std::vector<ChessPieceBase*> activeChessPieces = {
			player1Pawn1,
		player1Pawn2,
		player1Pawn3,
		player1Pawn4,
		player1Pawn5,
		player1Pawn6,
		player1Pawn7,
		player1Pawn8,
		player2Pawn1,
		player2Pawn2,
		player2Pawn3,
		player2Pawn4,
		player2Pawn5,
		player2Pawn6,
		player2Pawn7,
		player2Pawn8,
		player1Rook1,
		player1Rook2,
		bishop1,
		player1Knight1,
		player1Knight2,
		player1Bishop1,
		player1Bishop2,
		player1Queen,
		player1King,
	};


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
					
								if (!currentBoardSquareStruct.chessPieceId.empty() && currentBoardSquareStruct.chessPieceId.size() > 0) {
									logger("found chess piece");
										for (ChessPieceBase* activeChessPiece : activeChessPieces) {
											if (activeChessPiece->id == currentBoardSquareStruct.chessPieceId) {
												currentlySelectedChessPiece.selectedChessPiece = activeChessPiece;
											}
										};


									currentlySelectedChessPiece.selectedDefaultColor = currentBoardSquareStruct.boardSquare.getFillColor();
									if(currentBoardSquareStruct.boardSquare.getFillColor() != sf::Color{ 224,212,116 }) currentBoardSquareStruct.boardSquare.setFillColor(sf::Color{ 224,212,116 });
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
								ChessPieceBase* currentChessPiece = nullptr;

								for (ChessPieceBase* activeChessPiece : activeChessPieces) {
									if (activeChessPiece->id == currentBoardSquareStruct.chessPieceId) {
										currentChessPiece = activeChessPiece;
									}
								}
									//Check if we can move from the Chess Piece derived class
								if (currentlySelectedChessPiece.selectedChessPiece->canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y), 
									currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion, 1)) {
									//Check if we try to take our own chess piece
									if (currentBoardSquareStruct.chessPieceId.size() > 0 && currentlySelectedChessPiece.selectedChessPiece->player == currentChessPiece->player) {
										currentlySelectedChessPiece.selectedChessPiece = nullptr;
										currentlySelectedChessPiece.isCurrentlySelected = false;
										continue;
									}

									//Check if we take other players chess piece
									if (currentChessPiece != nullptr && currentChessPiece != currentlySelectedChessPiece.selectedChessPiece && currentlySelectedChessPiece.selectedChessPiece->player != currentChessPiece->player) {
										if (currentChessPiece->chessPieceType == "king") {
											hasAPlayerWon.isKingTaken = true;
											hasAPlayerWon.whichPlayerWon = currentlySelectedChessPiece.selectedChessPiece->player;
											break;
										}
										currentChessPiece->isChessPieceActive = false;
									}

									currentChessPiece = currentlySelectedChessPiece.selectedChessPiece;
									currentChessPiece->numberXPosition = currentBoardSquareStruct.numberXPosition;
									currentChessPiece->numberYPosition = currentBoardSquareStruct.numberYPosistion;
									currentBoardSquareStruct.chessPieceId = currentChessPiece->id;


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

						if (!currentlySelectedChessPiece.isCurrentlySelected) {
							logger("hit");


							for (int i = 0; i < boardSquareAttributes.size(); ++i) {
								boardSquareStruct& embeddedBoardSquareStruct = boardSquareAttributes.at(i);
								ChessPieceBase* currentChessPiece = nullptr;

								for (ChessPieceBase* activeChessPiece : activeChessPieces) {
									if (activeChessPiece->id == embeddedBoardSquareStruct.chessPieceId) {
										currentChessPiece = activeChessPiece;
									}
								};
								if (currentChessPiece != nullptr && embeddedBoardSquareStruct.numberXPosition == currentlySelectedChessPiece.selectedIndex.x && embeddedBoardSquareStruct.numberYPosistion == currentlySelectedChessPiece.selectedIndex.y) {
									embeddedBoardSquareStruct.boardSquare.setFillColor(currentlySelectedChessPiece.selectedDefaultColor);
								}

							}

							//Need to find old index and remove references to original chess piece position

							if (currentlySelectedChessPiece.canDeleteSelected && currentlySelectedChessPiece.selectedIndex.x != 0 && currentlySelectedChessPiece.selectedIndex.y != 0)
								for (int i = 0; i < boardSquareAttributes.size(); ++i) {
									boardSquareStruct& embeddedBoardSquareStruct = boardSquareAttributes.at(i);
									ChessPieceBase* currentChessPiece = nullptr;

									for (ChessPieceBase* activeChessPiece : activeChessPieces) {
										if (activeChessPiece->id == embeddedBoardSquareStruct.chessPieceId) {
											currentChessPiece = activeChessPiece;

										}
									};

									if (currentChessPiece != nullptr && embeddedBoardSquareStruct.numberXPosition == currentlySelectedChessPiece.selectedIndex.x && embeddedBoardSquareStruct.numberYPosistion == currentlySelectedChessPiece.selectedIndex.y) {
										embeddedBoardSquareStruct.chessPieceId.clear();
										embeddedBoardSquareStruct.boardSquare.setFillColor(currentlySelectedChessPiece.selectedDefaultColor);
										currentlySelectedChessPiece.selectedIndex = sf::Vector2f(0, 0);
										currentlySelectedChessPiece.canDeleteSelected = false;
									}
								};
						}
					}
				}
			}		
		}

			window.clear();
			for (boardSquareStruct boardSquareStruct : boardSquareAttributes) {
				window.draw(boardSquareStruct.boardSquare);
			}
			if(player1Pawn1->isChessPieceActive) window.draw(player1Pawn1->baseChessPiece);
			if (player1Pawn2->isChessPieceActive) window.draw(player1Pawn2->baseChessPiece);
			if (player1Pawn3->isChessPieceActive) window.draw(player1Pawn3->baseChessPiece);
			if (player1Pawn4->isChessPieceActive) window.draw(player1Pawn4->baseChessPiece);
			if (player1Pawn5->isChessPieceActive) window.draw(player1Pawn5->baseChessPiece);
			if (player1Pawn6->isChessPieceActive) window.draw(player1Pawn6->baseChessPiece);
			if (player1Pawn7->isChessPieceActive) window.draw(player1Pawn7->baseChessPiece);
			if (player1Pawn8->isChessPieceActive) window.draw(player1Pawn8->baseChessPiece);

			if(pawn2->isChessPieceActive) window.draw(pawn2->baseChessPiece);
			if (player1Rook2->isChessPieceActive) window.draw(player1Rook1->baseChessPiece);
			if (player1Rook2->isChessPieceActive) window.draw(player1Rook2->baseChessPiece);

			if (bishop1->isChessPieceActive) window.draw(bishop1->baseChessPiece);
			if (player1Knight1->isChessPieceActive) window.draw(player1Knight1->baseChessPiece);
			if (player1Knight2->isChessPieceActive) window.draw(player1Knight2->baseChessPiece);
			if (player1Bishop1->isChessPieceActive) window.draw(player1Bishop1->baseChessPiece);
			if (player1Bishop2->isChessPieceActive) window.draw(player1Bishop2->baseChessPiece);
			if (player1King->isChessPieceActive) window.draw(player1King->baseChessPiece);
			if (player1Queen->isChessPieceActive) window.draw(player1Queen->baseChessPiece);

			window.display();
	}

	return 0;
}