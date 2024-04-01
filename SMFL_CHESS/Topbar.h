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
		const sf::Vector2f resetButtonSize = sf::Vector2f(100, 40);
		const sf::Vector2f resetButtonPosistion = sf::Vector2f(1080, 75 / 2 - 20);
		const sf::Vector2f topbarPosition = sf::Vector2f(0, 0);
		const sf::Vector2f topbarSize = sf::Vector2f(1280, 75);

		Topbar(){
			font.loadFromFile("fonts/Butler_Regular.otf");
			topbarContainer.setPosition(topbarPosition);
			topbarContainer.setSize(topbarSize);
			TitleText.setFont(font);
			resetText.setFont(font);
			resetText.setString("Reset");
			resetText.setFillColor(sf::Color::White);
			resetButton.setFillColor(sf::Color::Blue);
			resetButton.setSize(resetButtonSize);
			resetButton.setPosition(resetButtonPosistion);
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

