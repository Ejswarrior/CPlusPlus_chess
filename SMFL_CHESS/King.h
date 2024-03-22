#pragma once
#include "ChessPieceBase.h"
#include <vector>

class King :
    public ChessPieceBase
{
public:
    King(std::string id,
        sf::Vector2f startingPosistion,
        std::string assetName,
        int player,
        std::string chessPieceType) : ChessPieceBase(id,
        startingPosistion,
        assetName,
        player,
        chessPieceType) {
        (*this).id = id;
        (*this).startingPosistion = startingPosistion;
        (*this).assetName = assetName;
        (*this).player = player;
        (*this).chessPieceType = chessPieceType;
    }
    bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType, std::vector<boardSquareStruct> boardSquareAttributes) override {
        int xDifference = numberXPosition - (*this).numberXPosition;
        int yDifference = numberYPosition - (*this).numberYPosition;
        if (xDifference < 0) xDifference = xDifference * -1;
        if (yDifference < 0) yDifference = yDifference * -1;

        if (xDifference == 1 || yDifference == 1) return true;

            return false;
    }
};

