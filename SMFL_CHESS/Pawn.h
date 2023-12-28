#pragma once
#include "ChessPieceBase.h"

class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
  
public: 
    bool canMovePosistions(sf::Vector2f newPosistion){
        sf::Vector2f distanceOfSquares = (*this).distanceOfSquares(newPosistion);

        std::cout << distanceOfSquares.y << std::endl;

        if (distanceOfSquares.y > 0 && distanceOfSquares.y <= 2 && distanceOfSquares.x == 0) {
            std::cout << "Hit this part" << std::endl;
            return true;
        }
        else return false;
    }
};

  