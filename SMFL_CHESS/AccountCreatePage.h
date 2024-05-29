#pragma once
#include "TextInput.h"
#include "Button.h"
#include "Text.h"

class AccountCreatePage
{

private:

public: 
	TextInput emailInput;
	TextInput passwordInput;
	TextInput nameInput;
	Text createAccountTitle;
	sf::Font font;

	int middleOfPage = 1280 / 2 - 150;


	AccountCreatePage() : 
		emailInput{ sf::Vector2f(middleOfPage, 200) }, nameInput{ sf::Vector2f(middleOfPage, 290) }, passwordInput{ sf::Vector2f(middleOfPage, 380) },
		createAccountTitle{font, 32, sf::Vector2f(middleOfPage - 50, 55), "Create an account"} {


	}


	void drawPage(sf::RenderWindow& window) {
		emailInput.draw(window);
		passwordInput.draw(window);
		nameInput.draw(window);
		createAccountTitle.draw(window);
	}
};

