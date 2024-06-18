#pragma once
#include <SFML/Network.hpp>
#include <iostream>
class HTTPService
{

	public:
		sf::Http http;

		HTTPService() {
			http.setHost("http://127.0.0.1", 5052);
		}

		sf::Http::Response get(std::string uri) {
			sf::Http::Request request;
			request.setMethod(sf::Http::Request::Get);
			request.setUri(uri);

			sf::Http::Response response = http.sendRequest(request);
			return response;
		}

		sf::Http::Response post(std::string uri, std::string stream) {
			sf::Http::Request request;
			request.setMethod(sf::Http::Request::Post);
			request.setUri(uri);
			request.setField("Content-Type", "application/x-www-form-urlencoded");
			sf::Http::Response response = http.sendRequest(request);
			return response;
		}




};

