#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <format> 

class WinMenu
{
private:
	sf::Font font;
	sf::Text winText;
	sf::Text pressText;
	sf::RectangleShape rectangle;

public: 

	int player = 0;


	WinMenu() {
		font.loadFromFile("fonts/Butler_Regular.otf");
	
		rectangle.setSize(sf::Vector2f(350, 250));
		rectangle.setPosition(sf::Vector2f(1280 / 2 - 175, 360 - 125));
		winText.setFont(font);
		winText.setString(std::format("Player {} has Won!", player));
	
		winText.setCharacterSize(20);
		winText.setFillColor(sf::Color::Black);
		winText.setPosition(sf::Vector2f(1280 / 2 - 60, 360 - 75));

		pressText.setFont(font);
		pressText.setString("Press any button to continue");
		pressText.setCharacterSize(20);
		pressText.setFillColor(sf::Color::Black);
		pressText.setPosition(sf::Vector2f(1280 / 2 - 125, 360 + 55));

	}

	void drawMenu(sf::RenderWindow& window) {
		window.draw(rectangle);
		window.draw(winText);
		window.draw(pressText);
	}

};

