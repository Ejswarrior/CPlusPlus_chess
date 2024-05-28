#pragma once
#include <SFML/Network.hpp>
class HTTPService
{

	public:
		sf::Http http;

		HTTPService() {
			http.setHost("http://localhost:5052/");
		}

		sf::Http::Response get(std::string uri) {
			sf::Http::Request request;
			request.setMethod(sf::Http::Request::Get);
			request.setUri(uri);
			request.setHttpVersion(1, 1);
			request.setField("Content-Type", "application/x-www-form-urlencoded");


			sf::Http::Response response = http.sendRequest(request);
			return response;
		}

};

