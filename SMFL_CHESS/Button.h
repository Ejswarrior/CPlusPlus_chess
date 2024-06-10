#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "EventHelpers.h"

class Button
{

	private:

	public:
		sf::RectangleShape buttonContainer;
		sf::Text buttonText;
		sf::Font font;
		sf::Vector2f buttonPosition{0,0};
		sf::Vector2f buttonSize{ 0,0 };
		std::string variant = "Primary";
		bool disabled = false;

		Button(const std::string buttonTextValue,  sf::Vector2f newButtonPosition,  sf::Vector2f newButtonSize, const std::string newVariant) {
			font.loadFromFile("fonts/Butler_Regular.otf");
			buttonContainer.setFillColor(newVariant == "Primary" ? sf::Color::Blue : sf::Color::White);
			buttonContainer.setSize(newButtonSize);
			buttonContainer.setPosition(newButtonPosition);
			buttonText.setFont(font);
			buttonText.setString(buttonTextValue);
			buttonText.setCharacterSize(16);
			buttonText.setPosition(sf::Vector2f(newButtonPosition.x + newButtonSize.x / 2 - ((buttonText.getString().getSize() / 2) * 16)/2, newButtonPosition.y + newButtonSize.y / 2 - 8));
			buttonText.setFillColor(newVariant == "Primary" ? sf::Color::White : sf::Color::Blue);
			buttonPosition = newButtonPosition;
			buttonSize = newButtonSize;
			variant = newVariant;
		}

		bool didButtonRecieveClick(sf::Vector2f mouseClickPosition) {
			if (disabled) return false;
			return clickedOnObject(buttonPosition, buttonSize, mouseClickPosition);
		}

		void disableButton() {
			disabled = true;

			buttonContainer.setFillColor(sf::Color{ 108,110,113});
			buttonText.setFillColor(sf::Color{ 54,55,57 });
		}

		void enableButton() {
			disabled = false;

			buttonContainer.setFillColor(variant == "Primary" ? sf::Color::Blue : sf::Color::White);
			buttonText.setFillColor(variant == "Primary" ? sf::Color::White : sf::Color::Blue);
		}

		void draw(sf::RenderWindow& window) {
			window.draw(buttonContainer);
			window.draw(buttonText);
		}
};

