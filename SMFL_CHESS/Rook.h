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
        std::cout << (*this).numberYPosition << std::endl;
        std::cout << numberYPosition << std::endl;

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