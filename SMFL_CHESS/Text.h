#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
class Text
{

public:

		sf::Text sfmlText;
		std::string textValue = "";
		sf::Font font;

		Text(int characterSize, sf::Vector2f textPosition, std::string defaultText) {
			
			font.loadFromFile("fonts/Butler_Regular.otf");
			sfmlText.setFont(font);
			sfmlText.setCharacterSize(characterSize);
			sfmlText.setPosition(textPosition);
			sfmlText.setFillColor(sf::Color::White);
			sfmlText.setString(defaultText);
			textValue = defaultText;
		}

		void draw(sf::RenderWindow& window) {
			window.draw(sfmlText);
		}
};

