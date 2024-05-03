#pragma once
#include <SFML/Network.hpp>
#include <iostream>

class MultipleSocket
{
private:
	sf::TcpSocket socket;
	sf::Socket::Status socketStatus;
public: 
	void intializeSocket(std::string ipAddress, int port) {
		sf::TcpSocket socket;

		socketStatus = socket.connect(ipAddress, port);

			if (socketStatus != sf::Socket::Done) {
				std::cout << "connection successful" << std::endl;
				return;

				//Will need to handle erroring here 
			}
			else std::cout << "connection unsuccessful" << std::endl;

	}

	void sendData() {
		char data[100] = "H";



		if (socket.send(data, 100) != sf::Socket::Done) {
			std::cout << "Data sent successfully" << std::endl;
			return;

			//For handling error
		}

		else {
			std::cout << "Data sent unsuccessfully" << std::endl;

			//for sending so acknowledgement that it was sent
		}

	}

	void recieveData(auto data) {
		std::size_t recieved;
		if (socket.receive(data, 100, recieved) != sf::Socket::Done)
		{
			std::cout << "Data recieved successfully" << std::endl;
			// error...
		}
		else {
			std::cout << "Data recieved unsuccessfully" << std::endl;

			// for doing something with the data;
		}

		std::cout << recieved << std::endl;
	}

	sf::Packet createPacket(int y, int x) {
		sf::Packet packet;

		packet << y << x;

		return packet;
	}
};

