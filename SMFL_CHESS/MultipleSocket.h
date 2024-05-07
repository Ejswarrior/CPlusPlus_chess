#pragma once
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include "BoardSquareStruct.h"

class MultipleSocket
{
private:
	sf::TcpSocket socket;
	sf::Socket::Status socketStatus;
public: 
	void intializeSocket(std::string ipAddress, int port) {
		socketStatus = socket.connect(ipAddress, port);

			if (socketStatus != sf::Socket::Done) {
				std::cout << "connection unsuccessful" << std::endl;
				return;

				//Will need to handle erroring here 
			}
			else std::cout << "connection successful" << std::endl;

	}

	void sendData(std::vector<boardSquareStruct> boardSquareAttributes) {
		sf::Packet packet;

	/*	for (boardSquareStruct& currentBoardSquareStruct : boardSquareAttributes) {
			packet << currentBoardSquareStruct.chessPieceId << currentBoardSquareStruct.numberXPosition << currentBoardSquareStruct.numberYPosistion;
			packet << currentBoardSquareStruct.boardSquarePosistion.x << currentBoardSquareStruct.boardSquarePosistion.y;
		}*/
		boardSquareStruct moveValue = boardSquareAttributes.at(0);


		struct moveData {
			std::string chessPieceId;
			int numberXposition;
			int numberYposition;
		};

		moveData data = { moveValue.chessPieceId, moveValue.numberXPosition, moveValue.numberYPosistion };
	

		if (socket.send((char*)&data, sizeof(data)) != sf::Socket::Done) {
			std::cout << "Data sent unsuccessfully" << std::endl;
			return;

			//For handling error
		}

		else {
			std::cout << "Data sent successfully" << std::endl;

			//for sending so acknowledgement that it was sent
		}

	}

	void recieveData() {
		std::size_t recieved;
		char data[100];
		if (socket.receive(data, 100, recieved) != sf::Socket::Done)
		{
			std::cout << "Data recieved unsuccessfully" << std::endl;
			// error...
		}
		else {
			std::cout << "Data recieved successfully" << std::endl;

			// for doing something with the data;
		}

		std::cout << data << std::endl;
	}

	sf::Packet createPacket(int y, int x) {
		sf::Packet packet;

		packet << y << x;

		return packet;
	}
};

