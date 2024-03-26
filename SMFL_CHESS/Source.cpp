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
#include "BoardSquareStruct.h"


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
	int currentPlayerTurn = 1;
	int xPosistion = 0;
	int yPosistion = 0;
	int xPosistionCount = 1;
	int yPoisitionCount = 1;

	
	//Todo: Find a better way to initialize all the Chess pieces

	ChessPieceBase* player1Pawn1 = new Pawn("player1Pawn1", sf::Vector2f(0, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn2 = new Pawn("player1Pawn2", sf::Vector2f(boardSquareWidth, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn3 = new Pawn("player1Pawn3", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn4 = new Pawn("player1Pawn4", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn5 = new Pawn("player1Pawn5", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn6 = new Pawn("player1Pawn6", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn7 = new Pawn("player1Pawn7", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player1Pawn8 = new Pawn("player1Pawn8", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn");
	ChessPieceBase* player2Pawn1 = new Pawn("player2Pawn1", sf::Vector2f(0, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn2 = new Pawn("player2Pawn2", sf::Vector2f(boardSquareWidth, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn3 = new Pawn("player2Pawn3", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn4 = new Pawn("player2Pawn4", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn5 = new Pawn("player2Pawn5", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn6 = new Pawn("player2Pawn6", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn7 = new Pawn("player2Pawn7", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player2Pawn8 = new Pawn("player2Pawn8", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn");
	ChessPieceBase* player1Rook1 = new Rook("player1Rook1", sf::Vector2f(0, 0), "images/player1Rook.png", 1, "Rook");
	ChessPieceBase* player1Rook2 = new Rook("player1Rook2", sf::Vector2f(boardSquareWidth * 7, 0), "images/player1Rook.png", 1, "Rook");
	ChessPieceBase* player1Knight1 = new Knight("player1Knight1", sf::Vector2f(boardSquareWidth, 0), "images/knightPlayer1.svg.png", 1, "Knight");
	ChessPieceBase* player1Knight2 = new Knight("player1Knight2", sf::Vector2f(boardSquareWidth * 6, 0), "images/knightPlayer1.svg.png", 1, "Knight");
	ChessPieceBase* player1Bishop1 = new Bishop("player1Bishop1", sf::Vector2f(boardSquareWidth * 2, 0), "images/player1Bishop.png", 1, "Bishop");
	ChessPieceBase* player1Bishop2 = new Bishop("player1Bishop2", sf::Vector2f(boardSquareWidth * 5, 0), "images/player1Bishop.png", 1, "Bishop");
	ChessPieceBase* player1Queen = new Queen("player1Queen", sf::Vector2f(boardSquareWidth * 3, 0), "images/queenPlayer1.svg.png", 1, "Queen");
	ChessPieceBase* player1King = new King("player1King", sf::Vector2f(boardSquareWidth * 4, 0), "images/kingPlayer1.svg.png", 1, "King");
	ChessPieceBase* player2Rook1 = new Rook("player2Rook1", sf::Vector2f(0, boardSquareHeight * 7), "images/player2Rook.png", 1, "Rook");
	ChessPieceBase* player2Rook2 = new Rook("player2Rook2", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight * 7), "images/player2Rook.png", 2, "Rook");
	ChessPieceBase* player2Knight1 = new Knight("player2Knight1", sf::Vector2f(boardSquareWidth, boardSquareHeight * 7), "images/knightPlayer2.svg.png", 2, "Knight");
	ChessPieceBase* player2Knight2 = new Knight("player2Knight2", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight * 7), "images/knightPlayer2.svg.png", 2, "Knight");
	ChessPieceBase* player2Bishop1 = new Bishop("player2Bishop1", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight * 7), "images/player2Bishop.png", 2, "Bishop");
	ChessPieceBase* player2Bishop2 = new Bishop("player2Bishop2", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight * 7), "images/player2Bishop.png", 2, "Bishop");
	ChessPieceBase* player2Queen = new Queen("player2Queen", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight * 7), "images/queenPlayer2.svg.png", 2, "Queen");
	ChessPieceBase* player2King = new King("player2King", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight * 7), "images/kingPlayer2.svg.png", 2, "King");


	selectedChessPieceStruct currentlySelectedChessPiece;
	

	if (!initialized) {
		for (int i = 0; i <= 64; i++) {

			boardSquareStruct boardSquareStruct;
			if (i == 0) {
				boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, 0));
				boardSquareStruct.boardSquarePosistion = sf::Vector2f(0, 0);
				boardSquareStruct.numberXPosition = 1;
				boardSquareStruct.numberYPosistion = 1;
		
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

				if (i == 48) {
					setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn1, 1, 7);
				}
				if(i == 56) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Rook1, 1, 8);

			}

			else {
				if (i == 7) {
				
					setChessPieceBoardSquareAttributes(boardSquareStruct, player1Rook2, 1, 7);
				}
			
				if (i == 9) {
					setChessPieceBoardSquareAttributes(boardSquareStruct, player1Pawn2, 2, 2);
			
				}
				if (i == 10) {
					boardSquareStruct.chessPieceId = player1Pawn3->id;
					player1Pawn3->numberYPosition = 2;
					player1Pawn3->numberXPosition = 3;
				}
				if (i == 11) {
					boardSquareStruct.chessPieceId = player1Pawn4->id;
					player1Pawn4->numberYPosition = 2;
					player1Pawn4->numberXPosition = 4;
				}
				if (i == 12) {
					boardSquareStruct.chessPieceId = player1Pawn5->id;
					player1Pawn5->numberYPosition = 2;
					player1Pawn5->numberXPosition = 5;
				}
				if (i == 13) {
					boardSquareStruct.chessPieceId = player1Pawn6->id;
					player1Pawn6->numberYPosition = 2;
					player1Pawn6->numberXPosition = 6;
				}
				if (i == 14) {
					boardSquareStruct.chessPieceId = player1Pawn7->id;
					player1Pawn7->numberYPosition = 2;
					player1Pawn7->numberXPosition = 7;
				}
				if (i == 15) {
					boardSquareStruct.chessPieceId = player1Pawn8->id;
					player1Pawn8->numberYPosition = 2;
					player1Pawn8->numberXPosition = 8;
				}
				
				if (i == 49) {
					setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn2, 2, 7);

				}
				if (i == 50) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn3, 3, 7);
				if (i == 51) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn4, 4, 7);
				if (i == 52) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn5, 5, 7);
				if (i == 53) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn6, 6, 7);
				if (i == 54) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn7, 7, 7);
				if (i == 55) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Pawn8, 8, 7);
				if (i == 57) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Knight1, 2, 8);
				if (i == 58) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Bishop1, 3, 8);
				if (i == 59) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Queen, 4, 8);
				if (i == 60) setChessPieceBoardSquareAttributes(boardSquareStruct, player2King, 5, 8);
				if (i == 61) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Bishop2, 6, 8);
				if (i == 62) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Knight2, 7, 8);
				if (i == 63) setChessPieceBoardSquareAttributes(boardSquareStruct, player2Rook2, 8, 8);



				
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
		player1Knight1,
		player1Knight2,
		player1Bishop1,
		player1Bishop2,
		player1Queen,
		player1King,
		player2Rook1,
		player2Rook2,
		player2Knight1,
		player2Knight2,
		player2Bishop1,
		player2Bishop2,
		player2Queen,
		player2King,
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
									std::cout << currentPlayerTurn << std::endl;
										for (ChessPieceBase* activeChessPiece : activeChessPieces) {
											if (activeChessPiece->id == currentBoardSquareStruct.chessPieceId && activeChessPiece->player == currentPlayerTurn) {
												currentlySelectedChessPiece.selectedChessPiece = activeChessPiece;
											}
										};

										if (currentlySelectedChessPiece.selectedChessPiece != nullptr) {
											currentlySelectedChessPiece.selectedDefaultColor = currentBoardSquareStruct.boardSquare.getFillColor();
											if (currentBoardSquareStruct.boardSquare.getFillColor() != sf::Color{ 224,212,116 }) currentBoardSquareStruct.boardSquare.setFillColor(sf::Color{ 224,212,116 });
											currentlySelectedChessPiece.isCurrentlySelected = true;
											currentlySelectedChessPiece.selectedIndex = sf::Vector2f(currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion);
										}
								
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
									currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion, 1, boardSquareAttributes)) {
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
									currentPlayerTurn = currentPlayerTurn == 1 ? 2 : 1;
									std::cout << currentPlayerTurn << std::endl;
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

			for (ChessPieceBase* chessPiece : activeChessPieces) {
				if (chessPiece->isChessPieceActive) window.draw(chessPiece->baseChessPiece);

			}
			window.display();
	}

	return 0;
}