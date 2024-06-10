#pragma once
#include "ChessPieceBase.h"
#include <vector>

class Queen :
    public ChessPieceBase
{
public: 
    Queen(std::string id,
        sf::Vector2f startingPosistion,
        std::string assetName,
        int player,
        std::string chessPieceType, sf::Vector2f startingIndexes, int startingBoardSquareIndex) : ChessPieceBase(id,
            startingPosistion,
            assetName,
            player,
            chessPieceType, startingIndexes, startingBoardSquareIndex) {
        (*this).id = id;
        (*this).startingPosistion = startingPosistion;
        (*this).assetName = assetName;
        (*this).player = player;
        (*this).chessPieceType = chessPieceType;
        (*this).startingIndexes = startingIndexes;
        (*this).startingBoardSquareIndex = startingBoardSquareIndex;
    }

    bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType, std::vector<boardSquareStruct> boardSquareAttributes) override {

        int xDifference = numberXPosition - (*this).numberXPosition;
        int yDifference = numberYPosition - (*this).numberYPosition;
        if (xDifference < 0) xDifference = xDifference * -1;
        if (yDifference < 0) yDifference = yDifference * -1;

        for (boardSquareStruct boardSquare : boardSquareAttributes) {
            int boardSquareXDifference = boardSquare.numberXPosition - (*this).numberXPosition;
            int boardSquareYDifference = boardSquare.numberYPosistion - (*this).numberYPosition;
            if (boardSquareXDifference < 0) boardSquareXDifference = boardSquareXDifference * -1;
            if (boardSquareYDifference < 0) boardSquareYDifference = boardSquareYDifference * -1;
            if (numberYPosition == (*this).numberYPosition && boardSquare.numberYPosistion == (*this).numberYPosition && boardSquare.chessPieceId.size() > 0 && (numberXPosition > (*this).numberXPosition && boardSquare.numberXPosition < numberXPosition && boardSquare.numberXPosition > (*this).numberXPosition || numberXPosition < (*this).numberXPosition && boardSquare.numberXPosition > numberXPosition && boardSquare.numberXPosition  < (*this).numberXPosition)) {
                return false;
            }

            else if (numberXPosition == (*this).numberXPosition && boardSquare.numberXPosition == (*this).numberXPosition && boardSquare.chessPieceId.size() > 0 && (numberYPosition > (*this).numberYPosition && boardSquare.numberYPosistion < numberYPosition && boardSquare.numberYPosistion > (*this).numberYPosition || numberYPosition < (*this).numberYPosition && boardSquare.numberYPosistion > numberYPosition && boardSquare.numberYPosistion < (*this).numberYPosition)) {
                return false;
            }

       
                if (boardSquare.chessPieceId.size() == 0 || boardSquareYDifference == 0 || boardSquareXDifference == 0 || boardSquareXDifference != boardSquareYDifference) continue;

                if (numberYPosition > (*this).numberYPosition && numberXPosition > (*this).numberXPosition && boardSquare.numberYPosistion > (*this).numberYPosition && boardSquare.numberXPosition > (*this).numberXPosition && boardSquare.numberYPosistion <= numberYPosition && boardSquare.numberXPosition <= numberXPosition) {

                    return false;
                }
                else if (numberYPosition < (*this).numberYPosition && numberXPosition < (*this).numberXPosition && boardSquare.numberYPosistion < (*this).numberYPosition && boardSquare.numberXPosition < (*this).numberXPosition && boardSquare.numberYPosistion >= numberYPosition && boardSquare.numberXPosition >= numberXPosition) {

                    return false;
                }
                else if (numberYPosition > (*this).numberYPosition && numberXPosition < (*this).numberXPosition && boardSquare.numberYPosistion >(*this).numberYPosition && boardSquare.numberXPosition < (*this).numberXPosition && boardSquare.numberYPosistion <= numberYPosition && boardSquare.numberXPosition >= numberXPosition) {

                    return false;
                }
                else if (numberYPosition < (*this).numberYPosition && numberXPosition >(*this).numberXPosition && boardSquare.numberYPosistion < (*this).numberYPosition && boardSquare.numberXPosition >(*this).numberXPosition && boardSquare.numberYPosistion >= numberYPosition && boardSquare.numberXPosition <= numberXPosition) {

                    return false;
                }

            
        }

        if (xDifference == yDifference || numberXPosition != (*this).numberXPosition && numberYPosition == (*this).numberYPosition || numberYPosition != (*this).numberYPosition && numberXPosition == (*this).numberXPosition || (xDifference == 1 && yDifference == 2 || xDifference == 2 && yDifference == 1)) return true;

        return false;
    }
};

