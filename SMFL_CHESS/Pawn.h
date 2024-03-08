#pragma once
#include "ChessPieceBase.h"
#include "struct_header.h"


class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
  
public:
    int numberOfMoves = 0;
     bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType) override {
         std::cout << (*this).player << std::endl;
         std::cout << playerType << std::endl;
        int totalMoves = numberOfMoves == 0 ? 2 : 1;
        if ((*this).player == 1) 
        {
            if (numberYPosition <= (*this).numberYPosition + totalMoves && numberXPosition == (*this).numberXPosition || playerType != (*this).player && numberXPosition == (*this).numberXPosition + 1) {
                numberOfMoves == 0 && numberOfMoves++;
                return true;
            }

        }

        else if ((*this).player == 2) 
        {
            if (numberYPosition >= (*this).numberYPosition - totalMoves && numberXPosition == (*this).numberXPosition || playerType != (*this).player && numberXPosition == (*this).numberXPosition + 1 || numberXPosition == (*this).numberXPosition - 1) {
                numberOfMoves == 0 && numberOfMoves++;
                return true;
            }
        }
        return false;

    }
};

  