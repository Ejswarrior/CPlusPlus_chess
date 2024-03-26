#pragma once
#include <vector>
#include <iostream>
#include <string> 

struct loggerStruct {
	std::string moveMessage;
	int player;
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

	void updateMessages(int player, int newNumberXPosition, int newNumberYPosition, int oldNumberXPoistion, int oldNumberYposition, std::string chessPieceType) {
		std::string newXNumberToStringValue = convertToStringPosition(newNumberXPosition);
		std::string oldXNumberToStringValue = convertToStringPosition(oldNumberXPoistion);
		
		loggerStruct newMove;
	
		newMove.moveMessage = "Player " + std::to_string(player) + " has moved " + chessPieceType + " from " + oldXNumberToStringValue + std::to_string(oldNumberYposition) + " to " + newXNumberToStringValue + std::to_string(newNumberYPosition);
		newMove.player = player;
		gameMoves.push_back(newMove);

	}
};

