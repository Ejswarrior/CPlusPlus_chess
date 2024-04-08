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
#include "WinMenu.h"
#include "Topbar.h"
#include "SelectChessPieceMenu.h"
#include <algorithm>
#include <iterator>


void resetGame(std::vector<ChessPieceBase*> activeChessPieces) {
	for (ChessPieceBase* chessPiece : activeChessPieces) {
		chessPiece->baseChessPiece.setPosition(sf::Vector2f(chessPiece->startingPosistion.x, chessPiece->startingPosistion.y + 75));
	}
}

bool clickedOnObject(sf::Vector2f objectPosition, sf::Vector2f objectSize, sf::Vector2f mouseClickPosition) {

	if (mouseClickPosition.x > objectPosition.x && mouseClickPosition.x < objectPosition.x + objectSize.x
		&& mouseClickPosition.y > objectPosition.y && mouseClickPosition.y < objectPosition.y + objectSize.y)
		return true;
	else return false;

}


int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 795), "My First Window");
	window.setFramerateLimit(60);
	const int boardSquareWidth = 1280 / 8;
	const int boardSquareHeight = 720 / 8;
	const int startingYPostion = 75;
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
	WinMenu menuWin;
	ChessPieceMoves chessPieceMoves;
	Topbar topbar;
	SelectChessPieceMenu chessPieceMenu;

	//Todo: Find a better way to initialize all the Chess pieces

	ChessPieceBase* player1Pawn1 = new Pawn("player1Pawn1", sf::Vector2f(0, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(1, 2), 8);
	ChessPieceBase* player1Pawn2 = new Pawn("player1Pawn2", sf::Vector2f(boardSquareWidth, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(2,2), 9);
	ChessPieceBase* player1Pawn3 = new Pawn("player1Pawn3", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(3,2), 10);
	ChessPieceBase* player1Pawn4 = new Pawn("player1Pawn4", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(4, 2), 11);
	ChessPieceBase* player1Pawn5 = new Pawn("player1Pawn5", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(5, 2), 12);
	ChessPieceBase* player1Pawn6 = new Pawn("player1Pawn6", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(6, 2), 13);
	ChessPieceBase* player1Pawn7 = new Pawn("player1Pawn7", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(7, 2), 14);
	ChessPieceBase* player1Pawn8 = new Pawn("player1Pawn8", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight), "images/player1Pawn.png", 1, "Pawn", sf::Vector2f(8, 2), 15);
	ChessPieceBase* player2Pawn1 = new Pawn("player2Pawn1", sf::Vector2f(0, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(1, 7), 48);
	ChessPieceBase* player2Pawn2 = new Pawn("player2Pawn2", sf::Vector2f(boardSquareWidth, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(2, 7), 49);
	ChessPieceBase* player2Pawn3 = new Pawn("player2Pawn3", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(3, 7), 50);
	ChessPieceBase* player2Pawn4 = new Pawn("player2Pawn4", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(4, 7), 51);
	ChessPieceBase* player2Pawn5 = new Pawn("player2Pawn5", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(5, 7), 52);
	ChessPieceBase* player2Pawn6 = new Pawn("player2Pawn6", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(6, 7), 53);
	ChessPieceBase* player2Pawn7 = new Pawn("player2Pawn7", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(7, 7), 54);
	ChessPieceBase* player2Pawn8 = new Pawn("player2Pawn8", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight * 6), "images/player2Pawn.png", 2, "Pawn", sf::Vector2f(8,7), 55);
	ChessPieceBase* player1Rook1 = new Rook("player1Rook1", sf::Vector2f(0, 0), "images/player1Rook.png", 1, "Rook", sf::Vector2f(0, 0), 0);
	ChessPieceBase* player1Rook2 = new Rook("player1Rook2", sf::Vector2f(boardSquareWidth * 7, 0), "images/player1Rook.png", 1, "Rook", sf::Vector2f(8, 1), 7);
	ChessPieceBase* player1Knight1 = new Knight("player1Knight1", sf::Vector2f(boardSquareWidth, 0), "images/knightPlayer1.svg.png", 1, "Knight", sf::Vector2f(2, 1), 1);
	ChessPieceBase* player1Knight2 = new Knight("player1Knight2", sf::Vector2f(boardSquareWidth * 6, 0), "images/knightPlayer1.svg.png", 1, "Knight", sf::Vector2f(7, 1), 6);
	ChessPieceBase* player1Bishop1 = new Bishop("player1Bishop1", sf::Vector2f(boardSquareWidth * 2, 0), "images/player1Bishop.png", 1, "Bishop", sf::Vector2f(3, 1), 2);
	ChessPieceBase* player1Bishop2 = new Bishop("player1Bishop2", sf::Vector2f(boardSquareWidth * 5, 0), "images/player1Bishop.png", 1, "Bishop", sf::Vector2f(6, 1), 5);
	ChessPieceBase* player1Queen = new Queen("player1Queen", sf::Vector2f(boardSquareWidth * 3, 0), "images/queenPlayer1.svg.png", 1, "Queen", sf::Vector2f(4, 1), 3);
	ChessPieceBase* player1King = new King("player1King", sf::Vector2f(boardSquareWidth * 4, 0), "images/kingPlayer1.svg.png", 1, "King", sf::Vector2f(5, 1), 4);
	ChessPieceBase* player2Rook1 = new Rook("player2Rook1", sf::Vector2f(0, boardSquareHeight * 7), "images/player2Rook.png", 1, "Rook", sf::Vector2f(1, 8), 56);
	ChessPieceBase* player2Rook2 = new Rook("player2Rook2", sf::Vector2f(boardSquareWidth * 7, boardSquareHeight * 7), "images/player2Rook.png", 2, "Rook", sf::Vector2f(8, 8), 63);
	ChessPieceBase* player2Knight1 = new Knight("player2Knight1", sf::Vector2f(boardSquareWidth, boardSquareHeight * 7), "images/knightPlayer2.svg.png", 2, "Knight", sf::Vector2f(2, 8), 57);
	ChessPieceBase* player2Knight2 = new Knight("player2Knight2", sf::Vector2f(boardSquareWidth * 6, boardSquareHeight * 7), "images/knightPlayer2.svg.png", 2, "Knight", sf::Vector2f(7, 8), 62);
	ChessPieceBase* player2Bishop1 = new Bishop("player2Bishop1", sf::Vector2f(boardSquareWidth * 2, boardSquareHeight * 7), "images/player2Bishop.png", 2, "Bishop", sf::Vector2f(3, 8), 58);
	ChessPieceBase* player2Bishop2 = new Bishop("player2Bishop2", sf::Vector2f(boardSquareWidth * 5, boardSquareHeight * 7), "images/player2Bishop.png", 2, "Bishop", sf::Vector2f(6, 8), 61);
	ChessPieceBase* player2Queen = new Queen("player2Queen", sf::Vector2f(boardSquareWidth * 3, boardSquareHeight * 7), "images/queenPlayer2.svg.png", 2, "Queen", sf::Vector2f(4, 8), 59);
	ChessPieceBase* player2King = new King("player2King", sf::Vector2f(boardSquareWidth * 4, boardSquareHeight * 7), "images/kingPlayer2.svg.png", 2, "King", sf::Vector2f(5, 8), 60);


	selectedChessPieceStruct currentlySelectedChessPiece;


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

	auto intializeChessBoard = [player1Rook1, player1Pawn1, player2Pawn1, player2Rook1, player1Rook2, player1Pawn2, player1Pawn3, player1Pawn4, player1Pawn5, player1Pawn6, player1Pawn7, player1Pawn8, 
		player2Pawn2, player2Pawn3, player2Pawn4, player2Pawn5, player2Pawn6, player2Pawn7, player2Pawn8, player2Knight1, player2Bishop1, player2Queen, player2King, player2Bishop2, player2Knight2, player2Rook2,
		player1Knight1, player1Knight2, player1Bishop1, player1Bishop2, player1Queen, defaultBoardSquareDark, defaultBoardSquareLight, activeChessPieces]()
	{		
			std::vector<boardSquareStruct> boardSqaureIntializer;
			int xPosistion = 0;
			int yPosistion = startingYPostion;
			int xPosistionCount = 1;
			int yPoisitionCount = 1;
			for (int i = 0; i < 64; i++) {

				boardSquareStruct boardSquareStruct;
	
				if (i == 0) {
					boardSquareStruct.boardSquare.setPosition(sf::Vector2f(0, startingYPostion));
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
				auto currentChessPieceIndex = std::find_if(activeChessPieces.begin(), activeChessPieces.end(), [&i](ChessPieceBase* currentChessPiece) {return currentChessPiece->startingBoardSquareIndex == i; });
				if (currentChessPieceIndex != activeChessPieces.end()) {
					auto index = std::distance(activeChessPieces.begin(), currentChessPieceIndex);
					activeChessPieces[index]->setChessPieceAttributes(i, boardSquareStruct);
				}
				else {
					activeChessPieces[activeChessPieces.size() - 1]->setChessPieceAttributes(i, boardSquareStruct);
				}
				boardSquareStruct.boardSquare.setSize(sf::Vector2f(boardSquareWidth, boardSquareHeight));
				if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 == 0 || i % 2 > 0 && yPosistion / boardSquareHeight % 2 > 0) boardSquareStruct.boardSquare.setFillColor(defaultBoardSquareDark);
				else if (i % 2 == 0 && yPosistion / boardSquareHeight % 2 > 0 || i % 2 > 0 && yPosistion / boardSquareHeight % 2 == 0) boardSquareStruct.boardSquare.setFillColor(defaultBoardSquareLight);

				else boardSquareStruct.boardSquare.setFillColor(sf::Color::White);

				 boardSqaureIntializer.push_back(boardSquareStruct);
			}
			return boardSqaureIntializer;
	};
	

	if (!initialized) {
		boardSquareAttributes = intializeChessBoard();
	}
	initialized = true;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (hasAPlayerWon.isKingTaken && event.type == sf::Event::KeyPressed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{


				if (event.mouseButton.button == sf::Mouse::Left) 
				{	
					if (hasPawnReachedEnd) {
						for (int i = 0; i <= 3; i++) {
							sf::Vector2f selectChessPieceListItem = chessPieceMenu.listItemPositions[i];

							if (clickedOnObject(selectChessPieceListItem, chessPieceMenu.listItemSize, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
								switch (i) {
								case 0:
									ChessPieceBase * currentPawn;

									for (int i = 0; i < activeChessPieces.size(); i++) {
										ChessPieceBase* currentChessPiece = activeChessPieces[i];

										if (currentChessPiece->chessPieceType == "Pawn" && currentChessPiece->isChessPieceActive && currentChessPiece->pawnHasReachedEnd) {
											ChessPieceBase* newBishopPlayer1 = new Bishop("player1NewBishop", currentChessPiece->posistion, "images/player1Bishop.png", currentChessPiece->player, "Bishop", currentChessPiece->startingIndexes, currentChessPiece->boardSquareIndex);
											newBishopPlayer1->numberXPosition = currentChessPiece->numberXPosition;
											newBishopPlayer1->numberYPosition = currentChessPiece->numberYPosition;
											boardSquareAttributes[currentChessPiece->boardSquareIndex].chessPieceId = newBishopPlayer1->id;
											activeChessPieces.push_back(newBishopPlayer1);
											currentChessPiece->isChessPieceActive = false;
										}
									}
									break;
								case 1:
									logger("Queen");
									break;
								case 2:
									logger("Rook");
									break;
								case 3:
									logger("Knight");
									break;
								}
							};
						}
					}


					if (clickedOnObject(topbar.resetButtonPosistion, topbar.resetButtonSize, sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
						resetGame(activeChessPieces);
						boardSquareAttributes.clear();
						boardSquareAttributes = intializeChessBoard();
					}
					//Select the Chess Piece
					if (!currentlySelectedChessPiece.isCurrentlySelected) {
						for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							if (clickedOnObject(boardSquarePosistion, sf::Vector2f(boardSquareWidth, boardSquareHeight), sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
						
								if (!currentBoardSquareStruct.chessPieceId.empty() && currentBoardSquareStruct.chessPieceId.size() > 0) {
									logger(currentBoardSquareStruct.chessPieceId);
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
						for (int i = 0; i < boardSquareAttributes.size(); i++) {
							boardSquareStruct& currentBoardSquareStruct = boardSquareAttributes[i];
							sf::RectangleShape boardSquare = currentBoardSquareStruct.boardSquare;
							sf::Vector2f boardSquarePosistion = boardSquare.getPosition();
							//Check for mouse position compared to boardSquare
							if (clickedOnObject(boardSquarePosistion, sf::Vector2f(boardSquareWidth, boardSquareHeight) , sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
								ChessPieceBase* currentChessPiece = nullptr;

								for (ChessPieceBase* activeChessPiece : activeChessPieces) {
									if (activeChessPiece->id == currentBoardSquareStruct.chessPieceId) {
										currentChessPiece = activeChessPiece;
									}
								}
									//Check if we can move from the Chess Piece derived class
								if (currentlySelectedChessPiece.selectedChessPiece->canMovePosistions(sf::Vector2f(boardSquarePosistion.x, boardSquarePosistion.y), 
									currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion, currentChessPiece != nullptr ? currentChessPiece->player : 0, boardSquareAttributes)) {
									//Check if we try to take our own chess piece
									logger("can move position");
									if (currentBoardSquareStruct.chessPieceId.size() > 0 && currentlySelectedChessPiece.selectedChessPiece->player == currentChessPiece->player) {
										logger(currentBoardSquareStruct.chessPieceId);
										currentlySelectedChessPiece.selectedChessPiece = nullptr;
										currentlySelectedChessPiece.isCurrentlySelected = false;
										continue;
									}

									//Check if we take other players chess piece
									if (currentChessPiece != nullptr && currentChessPiece != currentlySelectedChessPiece.selectedChessPiece && currentlySelectedChessPiece.selectedChessPiece->player != currentChessPiece->player) {
										if (currentChessPiece->chessPieceType == "King") {
											menuWin.player = currentlySelectedChessPiece.selectedChessPiece->player;
											hasAPlayerWon.isKingTaken = true;
											hasAPlayerWon.whichPlayerWon = currentlySelectedChessPiece.selectedChessPiece->player;
											break;
										}
										currentChessPiece->isChessPieceActive = false;
									}

									currentChessPiece = currentlySelectedChessPiece.selectedChessPiece;
									currentChessPiece->boardSquareIndex = i;

									currentBoardSquareStruct.chessPieceId = currentChessPiece->id;

									chessPieceMoves.updateMoves(currentlySelectedChessPiece.selectedChessPiece->player, currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion, currentlySelectedChessPiece.selectedChessPiece->numberXPosition, currentlySelectedChessPiece.selectedChessPiece->numberYPosition, currentlySelectedChessPiece.selectedChessPiece->chessPieceType);
									currentChessPiece->numberXPosition = currentBoardSquareStruct.numberXPosition;
									currentChessPiece->numberYPosition = currentBoardSquareStruct.numberYPosistion;

									logger("right before move");

									sf::Vector2f moveCoordinates = sf::Vector2f(boardSquarePosistion.x + (boardSquareWidth / 2) - (chessPieceWidth / 2), boardSquarePosistion.y + (boardSquareHeight / 2) - (chessPieceHeight / 2));
									currentlySelectedChessPiece.selectedChessPiece->move(moveCoordinates, sf::Vector2f(currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion), hasPawnReachedEnd, currentBoardSquareStruct.numberXPosition, currentBoardSquareStruct.numberYPosistion);
									currentPlayerTurn = currentPlayerTurn == 1 ? 2 : 1;
										
									currentlySelectedChessPiece.isCurrentlySelected = false;
									currentlySelectedChessPiece.canDeleteSelected = true;
								;

								}
								// If we can't move remove selected Chess Piece
								else {
									currentlySelectedChessPiece.isCurrentlySelected = false;
									currentlySelectedChessPiece.selectedChessPiece = nullptr;
									continue;
								}
							}
						}

						if (!currentlySelectedChessPiece.isCurrentlySelected) {

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
										currentlySelectedChessPiece.selectedChessPiece = nullptr;
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
			if(hasAPlayerWon.isKingTaken) menuWin.drawMenu(window);
			if(hasPawnReachedEnd) chessPieceMenu.draw(window);
			topbar.draw(window);
			window.display();
	}

	return 0;
}