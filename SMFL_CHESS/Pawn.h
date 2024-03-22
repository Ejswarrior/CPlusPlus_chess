#pragma once
#include "ChessPieceBase.h"
#include <vector>


class ChessPieceBase;
class Pawn :
     public ChessPieceBase
{
 
   
public:
   Pawn(std::string id,
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


    int numberOfMoves = 0;
     bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType, std::vector<boardSquareStruct> boardSquareAttributes) override {
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

  