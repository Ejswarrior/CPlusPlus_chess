#pragma once
#include <SFML/Graphics.hpp>
#include "EventHelpers.h"

class TextInput
{
private: 
	sf::Text textValue;
	sf::Event sfmlEvent;
	sf::RectangleShape textInputContainer;
	sf::RectangleShape cursorIndicator;
	int characterPosition = 1;


	TextInput(sf::Event event, sf::Vector2f inputPosition) {
		sfmlEvent = event;
		textInputContainer.setPosition(inputPosition);
		textInputContainer.setSize(sf::Vector2f(300, 48));
		cursorIndicator.setSize(sf::Vector2f(1, 38));
	};

public: 
	bool focused = false;

	void checkForClick() {
		if (sfmlEvent.type == sf::Event::MouseButtonPressed && sfmlEvent.mouseButton.button == sf::Mouse::Left)
		{

			if (clickedOnObject(textInputContainer.getPosition(), textInputContainer.getSize(), sf::Vector2f(sfmlEvent.mouseButton.x, sfmlEvent.mouseButton.y))) {
					focused = true;
			}
			else focused = false;
		}
	}

	void voidCheckForKeyboardInput() {

		if (focused && sfmlEvent.type == sf::Event::KeyPressed && sfmlEvent.KeyPressed) {



		}

	}

	
};

