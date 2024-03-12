#pragma once
#include "ChessPieceBase.h"
#include "struct_header.h"


class ChessPieceBase;
class Rook :
    public ChessPieceBase
{

public:
    bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType) override {
        std::cout << (*this).numberYPosition << std::endl;
        std::cout << numberYPosition << std::endl;


        if (numberXPosition != (*this).numberXPosition && numberYPosition == (*this).numberYPosition || numberYPosition != (*this).numberYPosition && numberXPosition == (*this).numberXPosition)
            return true;

        return false;

    }
};