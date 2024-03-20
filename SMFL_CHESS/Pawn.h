#pragma once
#include "ChessPieceBase.h"
#include <vector>


class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
  
public:
    int numberOfMoves = 0;
     bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType) override {
         std::cout << (*this).numberYPosition << std::endl;
         std::cout << numberYPosition << std::endl;
        int totalMoves = numberOfMoves == 0 ? 2 : 1;
        if ((*this).player == 1) 
        {
            if ((*this).numberYPosition < numberYPosition && numberYPosition <= (*this).numberYPosition + totalMoves && numberXPosition == (*this).numberXPosition || playerType != (*this).player && numberXPosition == (*this).numberXPosition + 1) {
                numberOfMoves == 0 && numberOfMoves++;
                return true;
            }

        }

        else if ((*this).player == 2) 
        {
            if ((*this).numberYPosition > numberYPosition && numberYPosition >= (*this).numberYPosition - totalMoves && numberXPosition == (*this).numberXPosition || playerType != (*this).player && numberXPosition == (*this).numberXPosition + 1 || numberXPosition == (*this).numberXPosition - 1) {
                numberOfMoves == 0 && numberOfMoves++;
                return true;
            }
        }
        return false;

    }
};

  