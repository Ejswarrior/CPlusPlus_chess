#pragma once
#include <vector>
#include <iostream>
#include <string> 
#include <format>

struct loggerStruct {
	std::string moveMessage;
	int player;
	std::vector<int> newMoves;
	std::vector<int> oldMoves;
};
class ChessPieceMoves
{
private:

	std::vector<loggerStruct> gameMoves;

public: 
	
	std::string convertToStringPosition(int numberXPosition) {
		return numberXPosition == 1 ? "A" : numberXPosition == 2 ? "B" : numberXPosition == 3 ? "C" : numberXPosition == 4 ? "D"
			: numberXPosition == 5 ? "E" : numberXPosition == 6 ? "F" : numberXPosition == 7 ? "G" : "H";
	}

	void updateMoves (int player, int newNumberXPosition, int newNumberYPosition, int oldNumberXPoistion, int oldNumberYposition, std::string chessPieceType) {
		std::string newXNumberToStringValue = convertToStringPosition(newNumberXPosition);
		std::string oldXNumberToStringValue = convertToStringPosition(oldNumberXPoistion);
		
		loggerStruct newMove;
		newMove.moveMessage = std::format("Player {} has moved {} from {} {} to {} {}", std::to_string(player), chessPieceType, oldXNumberToStringValue, std::to_string(oldNumberYposition), newXNumberToStringValue, std::to_string(newNumberYPosition));
		newMove.player = player;
		newMove.newMoves = { newNumberXPosition, newNumberYPosition };
		newMove.oldMoves = { oldNumberXPoistion, oldNumberYposition };
		gameMoves.push_back(newMove);
	}

	void clearMoves(int player = 0) {
		if (player == 0) gameMoves.clear();

		else {
			for (int i = 0; i < gameMoves.size(); i++) {
				loggerStruct gameMove = gameMoves.at(i);

				if (gameMove.player == player) gameMoves.erase(gameMoves.begin() + i);
			}
		}
	}

	std::vector<loggerStruct> getMoves(int player = 0) {
		if(player == 0) return gameMoves;

		else {
			std::vector<loggerStruct> playerGameMoves;
				
				for (int i = 0; i < gameMoves.size(); i++) {
					loggerStruct gameMove = gameMoves.at(i);
					
					if (gameMove.player == player) playerGameMoves.push_back(gameMove);
				}

				return playerGameMoves;
		}
	}
};

