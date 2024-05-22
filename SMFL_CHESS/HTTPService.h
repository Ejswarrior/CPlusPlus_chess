#pragma once
#include <SFML/Network.hpp>
class HTTPService
{

	public:
		sf::Http http;

		HTTPService() {
			http.setHost("http://localhost:5052/");
		}


};

