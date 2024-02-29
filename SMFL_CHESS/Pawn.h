#pragma once
#include "ChessPieceBase.h"
#include "struct_header.h"


class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
  
public:
    int numberOfMoves = 0;
    std::vector<int> intialBoardSqaure = { 8, 9, 10, 11, 12, 13, 14, 15 };

    bool canMovePosistions(sf::Vector2f newPosistion, boardSquareStruct boardSquareStruct){
        sf::Vector2f distanceOfSquares = (*this).distanceOfSquares(newPosistion);

        int totalMoves = numberOfMoves == 0 ? 2 : 1;

        if (distanceOfSquares.y > 0 && distanceOfSquares.y <= totalMoves && distanceOfSquares.x == 0) {
            numberOfMoves++;
            return true;
        }
        else return false;
    }
};

  