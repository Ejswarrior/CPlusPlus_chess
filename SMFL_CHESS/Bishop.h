#pragma once
#include "ChessPieceBase.h"
#include <vector>

class Bishop:
    public ChessPieceBase
    {

    public:

        bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType) override {
   
            int xDifference = numberXPosition - (*this).numberXPosition;
            int yDifference = numberYPosition - (*this).numberYPosition;
            if (xDifference < 0) xDifference = xDifference * -1;
            if (yDifference < 0) yDifference = yDifference * -1;

            if (xDifference == yDifference) return true;
           
            return false;
        }

};

