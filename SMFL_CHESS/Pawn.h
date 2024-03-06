#pragma once
#include "ChessPieceBase.h"
#include "struct_header.h"


class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
  
public:
    int numberOfMoves = 0;
     bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition) override {
         std::cout << "hit child" << std::endl;
        sf::Vector2f distanceOfSquares = (*this).distanceOfSquares(newPosistion);

        int totalMoves = numberOfMoves == 0 ? 2 : 1;
        std::cout << numberYPosition << std::endl;
        std::cout << (*this).numberYPosition << std::endl;
        if (numberYPosition <= (*this).numberYPosition + totalMoves) {
            numberOfMoves == 0 && numberOfMoves++;
            return true;
        }

        else return false;
    }
};

  