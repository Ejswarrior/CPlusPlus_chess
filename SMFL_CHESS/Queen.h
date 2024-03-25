#pragma once
#include "ChessPieceBase.h"
#include <vector>

class Queen :
    public ChessPieceBase
{
public: 
    Queen(std::string id,
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
    bool canMovePosistions(sf::Vector2f newPosistion, int numberXPosition, int numberYPosition, int playerType, std::vector<boardSquareStruct> boardSquareAttributes) override {

        int xDifference = numberXPosition - (*this).numberXPosition;
        int yDifference = numberYPosition - (*this).numberYPosition;
        if (xDifference < 0) xDifference = xDifference * -1;
        if (yDifference < 0) yDifference = yDifference * -1;

        for (boardSquareStruct boardSquare : boardSquareAttributes) {
            int boardSquareXDifference = boardSquare.numberXPosition - (*this).numberXPosition;
            int boardSquareYDifference = boardSquare.numberYPosistion - (*this).numberYPosition;
            if (boardSquareXDifference < 0) boardSquareXDifference = boardSquareXDifference * -1;
            if (boardSquareYDifference < 0) boardSquareYDifference = boardSquareYDifference * -1;
            if (numberYPosition == (*this).numberYPosition && boardSquare.chessPieceId.size() > 0 && boardSquare.numberYPosistion > (*this).numberYPosition && boardSquare.numberYPosistion < numberYPosition && boardSquare.numberXPosition == numberXPosition) {
                return false;
            }

            else if (numberXPosition == (*this).numberXPosition && boardSquare.chessPieceId.size() > 0 && boardSquare.numberXPosition > (*this).numberXPosition && boardSquare.numberXPosition < numberYPosition && boardSquare.numberYPosistion == numberYPosition) {
                return false;
            }

            else if (numberXPosition < (*this).numberXPosition && boardSquare.chessPieceId.size() > 0 && boardSquareYDifference != 0 && boardSquareXDifference != 0 && boardSquareYDifference == boardSquareXDifference && (*this).numberXPosition > boardSquare.numberXPosition) {
                std::cout << (*this).numberXPosition << std::endl;
                std::cout << boardSquare.numberXPosition << std::endl;
                std::cout << boardSquare.chessPieceId << std::endl;
                return false;
            }
            else if (numberYPosition < (*this).numberYPosition && boardSquare.chessPieceId.size() > 0 && boardSquareYDifference != 0 && boardSquareXDifference != 0 && boardSquareYDifference == boardSquareXDifference && (*this).numberYPosition > boardSquare.numberYPosistion) {
                std::cout << (*this).numberXPosition << std::endl;
                std::cout << boardSquare.numberXPosition << std::endl;
                std::cout << boardSquare.chessPieceId << std::endl;
                return false;
            }
            else if (numberYPosition < (*this).numberYPosition && boardSquare.chessPieceId.size() > 0 && boardSquareYDifference != 0 && boardSquareXDifference != 0 && boardSquareYDifference == boardSquareXDifference && (*this).numberYPosition > boardSquare.numberYPosistion) {
                std::cout << (*this).numberXPosition << std::endl;
                std::cout << boardSquare.numberXPosition << std::endl;
                std::cout << boardSquare.chessPieceId << std::endl;
                return false;
            }
            else if (numberXPosition > (*this).numberXPosition && boardSquare.chessPieceId.size() > 0 && boardSquareYDifference != 0 && boardSquareXDifference != 0 && boardSquareYDifference == boardSquareXDifference && (*this).numberXPosition < boardSquare.numberXPosition) {
                std::cout << boardSquare.chessPieceId << std::endl;
                return false;
            }
        }

        if (xDifference == yDifference || numberXPosition != (*this).numberXPosition && numberYPosition == (*this).numberYPosition || numberYPosition != (*this).numberYPosition && numberXPosition == (*this).numberXPosition || (xDifference == 1 && yDifference == 2 || xDifference == 2 && yDifference == 1)) return true;

        return false;
    }
};

