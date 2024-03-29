#pragma once
#include <SFML/Graphics.hpp>

class Topbar
{	
	private: 
		sf::RectangleShape topbarContainer;
		sf::RectangleShape resetButton;
		sf::Text resetText; 
		sf::Text TitleText;
		sf::Font font;


	public: 
		Topbar(){
			font.loadFromFile("fonts/Butler_Regular.otf");
			topbarContainer.setPosition(sf::Vector2f(0, 0));
			topbarContainer.setSize(sf::Vector2f(1280, 75));
			TitleText.setFont(font);
			resetText.setFont(font);
			resetText.setString("Reset");
			resetText.setFillColor(sf::Color::White);
			resetButton.setFillColor(sf::Color::Blue);
			resetButton.setSize(sf::Vector2f(100, 40));
			resetButton.setPosition(sf::Vector2f(1080, 75/2 - 20 ));
			resetText.setPosition(sf::Vector2f(1090, 75 / 2 - 15));
			TitleText.setString("Welcome to chess!");
			TitleText.setCharacterSize(26);
			TitleText.setFillColor(sf::Color::Black);
			TitleText.setPosition(sf::Vector2f(50, 75 / 2 - 20));
		}

		void draw(sf::RenderWindow& window) { 
			window.draw(topbarContainer);
			window.draw(TitleText);
			window.draw(resetButton);
			window.draw(resetText);
		}
};

