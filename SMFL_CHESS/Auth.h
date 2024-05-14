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

	TextInput emailInput;
	Auth() : emailInput{sf::Vector2f(0, 0)} {

	};

	bool getAuthStatus() {
		return isAuthenticated;
	}


	void drawAuthPage(sf::RenderWindow& window) {
		emailInput.draw(window);
	}


};

