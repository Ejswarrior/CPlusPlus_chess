#pragma once

#include <SFML/Graphics.hpp>
#include "EventHelpers.h"
#include <iostream>
#include <vector>
class Auth
{
private: 
	bool isAuthenticated = false;
	int middleOfPage = 1280 / 2 - 150;

public: 
	TextInput emailInput = TextInput(sf::Vector2f(0, 0));
	TextInput passwordInput = TextInput(sf::Vector2f(0, 0));

	Auth() {
		emailInput = TextInput(sf::Vector2f(middleOfPage,  200));
		passwordInput = TextInput(sf::Vector2f(middleOfPage, 400));
	};

	bool getAuthStatus() {
		return isAuthenticated;
	}


	void drawAuthPage(sf::RenderWindow& window) {
		emailInput.draw(window);
		passwordInput.draw(window);
	}


};

