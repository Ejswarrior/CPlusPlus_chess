#pragma once
#include "ChessPieceBase.h"

class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
  
public:
    int numberOfMoves = 0;

    bool canMovePosistions(sf::Vector2f newPosistion){
        sf::Vector2f distanceOfSquares = (*this).distanceOfSquares(newPosistion);

        std::cout << distanceOfSquares.y << std::endl;
        int totalMoves = numberOfMoves == 0 ? 2 : 1;

        if (distanceOfSquares.y > 0 && distanceOfSquares.y <= totalMoves && distanceOfSquares.x == 0) {
            std::cout << "Hit this part" << std::endl;
            numberOfMoves++;
            return true;
        }
        else return false;
    }
};

  