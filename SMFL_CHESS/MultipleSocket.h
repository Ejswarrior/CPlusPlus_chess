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
		socketStatus = socket.connect(ipAddress, port);

			if (socketStatus != sf::Socket::Done) {
				std::cout << "connection unsuccessful" << std::endl;
				return;

				//Will need to handle erroring here 
			}
			else std::cout << "connection successful" << std::endl;

	}

	void sendData() {
		std::string s = "hello";
		sf::Packet packet;
		packet << s;



		if (socket.send(packet) != sf::Socket::Done) {
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

