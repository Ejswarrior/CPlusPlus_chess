#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "EventHelpers.h"
#include <iostream>
#include <vector>
#include "TextInput.h"
#include "HTTPService.h"
#include "Button.h"
#include "Text.h"

class Auth
{
private:
	bool isAuthenticated = false;
	int middleOfPage = 1280 / 2 - 150;
	sf::Text emailSubtitle;
	sf::Text passwordSubtitle;
	sf::Text titleText;
	sf::Text loginText;
	sf::Font font;


public:

	void setUpText(sf::Text& textObj, const std::string textValue, const sf::Vector2f textPosition, const int characterSize) {
		textObj.setFont(font);
		textObj.setCharacterSize(characterSize);
		textObj.setPosition(textPosition);
		textObj.setFillColor(sf::Color::White);
		textObj.setString(textValue);
	}

	TextInput emailInput;
	TextInput passwordInput;
	HTTPService httpService;
	Button loginButton;
	Text noAccountText;

	Auth() : emailInput{ sf::Vector2f(middleOfPage, 250) }, passwordInput{ sf::Vector2f(middleOfPage, 340) }, 
		loginButton{ "Login", sf::Vector2f(middleOfPage, 480),sf::Vector2f(300,48), "Primary" }, noAccountText{16, sf::Vector2f(middleOfPage - 40, 500), "Create new account"} {
		font.loadFromFile("fonts/Butler_Regular.otf");
		setUpText(emailSubtitle, "Email", sf::Vector2f(middleOfPage, 225), 16);
		setUpText(passwordSubtitle, "Password", sf::Vector2f(middleOfPage, 315), 16);
		setUpText(titleText, "Welcome to Simple Fast Chess", sf::Vector2f(middleOfPage - 50, 55), 32);
	};

	bool clickedOnCreateAccount(sf::Vector2f mouseClickPosition) {
		const int characterSize = noAccountText.sfmlText.getCharacterSize();

		return clickedOnObject(noAccountText.sfmlText.getPosition(), sf::Vector2f(characterSize / 2 * 14, characterSize), mouseClickPosition);
	};

	bool getAuthStatus() {
		return isAuthenticated;
	}

	bool authenticateUser(std::string email, std::string password) {
		if (email.size() == 0 || password.size() == 0) return false;
		
		sf::Http::Response loginResponse = httpService.get("/login");

		isAuthenticated = loginResponse.Ok ? true : false;

	}


	void drawAuthPage(sf::RenderWindow& window) {
		emailInput.draw(window);
		passwordInput.draw(window);
		noAccountText.draw(window);
		window.draw(emailSubtitle);
		window.draw(passwordSubtitle);
		window.draw(titleText);
		loginButton.draw(window);
		window.draw(loginText);
	}


};

