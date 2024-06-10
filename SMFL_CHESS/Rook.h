#pragma once
#include "ChessPieceBase.h"
#include <vector>


class ChessPieceBase;
class Rook :
    public ChessPieceBase
{

public:
    Rook(std::string id,
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

        //In chess we dont want some chess pieces to move over each other. The knight is the exception. Here we check if chessPiece is in between the selected move area and return false if truthy.
        for (boardSquareStruct boardSquare : boardSquareAttributes) {
            if (boardSquare.chessPieceId.size() > 0 && boardSquare.numberYPosistion > (*this).numberYPosition && boardSquare.numberYPosistion < numberYPosition && boardSquare.numberXPosition == numberXPosition) {
                return false;
            }

            else if (boardSquare.chessPieceId.size() > 0 && boardSquare.numberXPosition > (*this).numberXPosition && boardSquare.numberXPosition < numberYPosition && boardSquare.numberYPosistion == numberYPosition) {
                return false;
            }
        }

        if (numberXPosition != (*this).numberXPosition && numberYPosition == (*this).numberYPosition || numberYPosition != (*this).numberYPosition && numberXPosition == (*this).numberXPosition) {
            return true;

        }

        return false;

    }
};