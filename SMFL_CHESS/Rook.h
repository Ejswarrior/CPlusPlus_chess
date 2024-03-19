#pragma once
#include "ChessPieceBase.h"
#include "struct_header.h"


class ChessPieceBase;
class Rook :
    public ChessPieceBase
{

public:
    bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType, std::vector<boardSquareStruct>* boardSquareAttributes) override {
        std::cout << (*this).numberYPosition << std::endl;
        std::cout << numberYPosition << std::endl;

        if (numberXPosition != (*this).numberXPosition && numberYPosition == (*this).numberYPosition) {
            for (int i = 0; i < 64; ++i) {
                boardSquareStruct& currentBoardSquare = boardSquareAttributes.at(i);
                if (currentBoardSquare.numberXPosition < numberXPosition && currentBoardSquare.numberXPosition >(*this).numberXPosition) {
                    logger(currentBoardSquare.chessPiece->id);
                }
            }
        }

        if (numberXPosition != (*this).numberXPosition && numberYPosition == (*this).numberYPosition || numberYPosition != (*this).numberYPosition && numberXPosition == (*this).numberXPosition)
            return true;

        return false;

    }
};