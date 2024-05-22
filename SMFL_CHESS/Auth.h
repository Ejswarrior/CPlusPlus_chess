#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "EventHelpers.h"
#include <iostream>
#include <vector>
#include "TextInput.h"

class Auth
{
private:
	bool isAuthenticated = false;
	int middleOfPage = 1280 / 2 - 150;
	sf::Text emailSubtitle;
	sf::Text passwordSubtitle;
	sf::Text titleText;
	sf::Font font;


public:

	TextInput emailInput;
	TextInput passwordInput;
	Auth() : emailInput{ sf::Vector2f(middleOfPage, 250) }, passwordInput{ sf::Vector2f(middleOfPage, 340) } {
		font.loadFromFile("fonts/Butler_Regular.otf");
		emailSubtitle.setFont(font);
		emailSubtitle.setCharacterSize(16);
		emailSubtitle.setPosition(sf::Vector2f(middleOfPage, 225));
		emailSubtitle.setFillColor(sf::Color::White);
		emailSubtitle.setString("Email");
		passwordSubtitle.setFont(font);
		passwordSubtitle.setCharacterSize(16);
		passwordSubtitle.setPosition(sf::Vector2f(middleOfPage, 315));
		passwordSubtitle.setFillColor(sf::Color::White);
		passwordSubtitle.setString("Password");
		titleText.setFont(font);
		titleText.setCharacterSize(32);
		titleText.setPosition(sf::Vector2f(middleOfPage - 50, 55));
		titleText.setFillColor(sf::Color::White);
		titleText.setString("Welcome to Simple Fast Chess");

	};

	bool getAuthStatus() {
		return isAuthenticated;
	}

	bool authenticateUser(std::string email, std::string password) {

	}


	void drawAuthPage(sf::RenderWindow& window) {
		emailInput.draw(window);
		passwordInput.draw(window);
		window.draw(emailSubtitle);
		window.draw(passwordSubtitle);
		window.draw(titleText);
	}


};

