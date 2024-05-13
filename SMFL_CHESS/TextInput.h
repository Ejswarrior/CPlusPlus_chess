#pragma once
#include <SFML/Graphics.hpp>
#include "EventHelpers.h"
#include <iostream>
#include <vector>


class TextInput
{


private: 
	sf::Text textValue;
	sf::RectangleShape textInputContainer;
	sf::RectangleShape cursorIndicator;
	int characterPosition = 1;
	sf::Font font;
	std::string inputString;
	std::vector<int> invalidTextCode = { 0 };

	sf::Vector2f getTextEndingPosition() {
		return textValue.findCharacterPos(textValue.getString().getSize() - 1);
	}

public: 

	TextInput(sf::Vector2f inputPosition) {
		font.loadFromFile("fonts/Butler_Regular.otf");
		textValue.setFont(font);
		textInputContainer.setPosition(inputPosition);
		textInputContainer.setSize(sf::Vector2f(300, 48));
		cursorIndicator.setSize(sf::Vector2f(1, 38));
		cursorIndicator.setFillColor(sf::Color::Black);
		cursorIndicator.setPosition(sf::Vector2f(inputPosition.x + 16, inputPosition.y - 8));
		textValue.setCharacterSize(26);
		textValue.setFillColor(sf::Color::Black);
		textValue.setPosition(sf::Vector2f(inputPosition.x + 16, inputPosition.y - 8));
	};

	bool focused = false;

	void checkForClick(sf::Event sfmlEvent) {
		if (sfmlEvent.type == sf::Event::MouseButtonPressed && sfmlEvent.mouseButton.button == sf::Mouse::Left)
		{

			if (clickedOnObject(textInputContainer.getPosition(), textInputContainer.getSize(), sf::Vector2f(sfmlEvent.mouseButton.x, sfmlEvent.mouseButton.y))) {
					focused = true;
			}
			else focused = false;
		}
	}

	void voidCheckForKeyboardInput(sf::Event sfmlEvent) {


		if (focused && sfmlEvent.type == sf::Event::TextEntered) {

			if (sfmlEvent.KeyPressed && sfmlEvent.key.code == 8) {
				sf::Vector2f cursorPosition = cursorIndicator.getPosition();
				if (inputString.size() > 0) {
					inputString.pop_back();
					textValue.setString(inputString);
					sf::Vector2f textSize = getTextEndingPosition();
					cursorIndicator.setPosition(inputString.size() == 0 ? textInputContainer.getPosition().x + 16 : textSize.x + textValue.getCharacterSize() / 2, cursorPosition.y);
				}
			}

			if (sfmlEvent.text.unicode < 0x80 && sfmlEvent.key.code != 8)
			{	
				sf::Vector2f cursorPosition = cursorIndicator.getPosition();

				inputString += (char)sfmlEvent.text.unicode;
				textValue.setString(inputString);
				sf::Vector2f textSize = getTextEndingPosition();
				cursorIndicator.setPosition(textSize.x + textValue.getCharacterSize()/2, cursorPosition.y);
			}
		

		}

	}

	void draw(sf::RenderWindow& window) {
		window.draw(textInputContainer);
		window.draw(textValue);
		if (focused) {
			window.draw(cursorIndicator);
		}
	}

	
};

 