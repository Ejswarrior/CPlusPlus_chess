#pragma once
#include <SFML/Network.hpp>

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
				return;

				//Will need to handle erroring here 
			}
	}

	void sendData(auto data) {

		if (socket.send(data, 1000) != sf::Socket::Done) {
			return;

			//For handling error
		}

		else {
			//for sending so acknowledgement that it was sent
		}

	}

	void recieveData(auto data) {
		if (socket.receive(data, 100, received) != sf::Socket::Done)
		{
			// error...
		}
		else {
			// for doing something with the data;
		}
	}

	sf::Packet createPacket(int y, int x) {
		sf::Packet packet;

		packet << y << x;

		return packet;
	}
};

