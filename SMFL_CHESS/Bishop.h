#pragma once
#include "ChessPieceBase.h"
#include <vector>

class Bishop:
    public ChessPieceBase
    {

    public:
        Bishop(std::string id,
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

            for (boardSquareStruct boardSquare : boardSquareAttributes) {
                int boardSquareXDifference = numberXPosition - boardSquare.numberXPosition;
                int boardSquareYDifference = numberYPosition - boardSquare.numberYPosistion;
                if (boardSquareXDifference < 0) boardSquareXDifference = boardSquareXDifference * -1;
                if (boardSquareYDifference < 0) boardSquareYDifference = boardSquareYDifference * -1;
                if (boardSquare.chessPieceId.size() > 0 && boardSquareYDifference == boardSquareXDifference && boardSquareXDifference < xDifference || boardSquareYDifference < yDifference) {
                    std::cout << boardSquare.chessPieceId << std::endl;
                }

            }

            if (xDifference < 0) xDifference = xDifference * -1;
            if (yDifference < 0) yDifference = yDifference * -1;

            if (xDifference == yDifference) return true;
           
            return false;
        }

};

