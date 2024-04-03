#pragma once
#include <SFML/Graphics.hpp>
#include "vector"

class SelectChessPieceMenu
{	
private: 
	sf::RectangleShape selectChessPeiceContainer;
	sf::RectangleShape bishopListItem;
	sf::RectangleShape QueenListItem;
	sf::RectangleShape rookListItem;
	sf::RectangleShape knightListItem;
	sf::Text bishopListItemText;
	sf::Text queenListItemText;
	sf::Text rookListItemText;
	sf::Text knightListItemText;
	sf::Font font;

	std::vector<sf::RectangleShape> listItems = {
		 bishopListItem,
		 QueenListItem,
		 rookListItem,
		 knightListItem
	};

	std::vector<sf::Text> listItemTexts = {
		 bishopListItemText,
		 queenListItemText,
		 rookListItemText,
		 knightListItemText,
	};

	std::vector<std::string> listItemStrings = {
		"Bishop",
		"Queen",
		"Rook",
		"Knight",
	};
	
public:
	const sf::Vector2f listItemSize = sf::Vector2f(400 - 24, 400 / 4 - 12);
	std::vector<sf::Vector2f> listItemPositions;

	sf::Vector2f getListItemPosition(int position) {
		int xPosition = 1280 / 2 - 200 + 12;
		int calculateYAmountDown = position != 0 ? ((400 / 4 - 6) * position) - 6 : 0;
		int yPostiton = 820 / 2 - 200 + (6 * position + 1) + calculateYAmountDown;
		sf::Vector2f listItemPosition = sf::Vector2f(xPosition, yPostiton);
		listItemPositions.push_back(listItemPosition);
		return listItemPosition;
	}

	sf::Vector2f getListItemTextPosition(int position) {
		int xPosition = 1280 / 2 - 200 + 12;
		int calculateYAmountDown = position != 0 ? ((400 / 4 - 6) * position) - 6 : 0;
		int yPostiton = 820 / 2 - 200 + (6 * position + 1) + calculateYAmountDown;

		return sf::Vector2f(xPosition + 12, yPostiton + (listItemSize.y - 44));
	}

	SelectChessPieceMenu() {
		font.loadFromFile("fonts/Butler_Regular.otf");
		selectChessPeiceContainer.setSize(sf::Vector2f(400, 400));
		selectChessPeiceContainer.setPosition(sf::Vector2f(1280 / 2 - 200, 820 / 2 - 200));
		for (int i = 0; i <= 3; i++) {
			sf::Text& listItemText = listItemTexts[i];
			listItemText.setFont(font);
			listItemText.setString(listItemStrings[i]);
			listItemText.setFillColor(sf::Color::White);
			listItemText.setPosition(getListItemTextPosition(i));
		}
	
		for (int i = 0; i <= 3; i++) {
			sf::RectangleShape& listItem = listItems[i];
			listItem.setSize(listItemSize);
			listItem.setPosition(getListItemPosition(i));
			listItem.setFillColor(sf::Color::Black);
		}
	}


	void draw(sf::RenderWindow& window) {
		window.draw(selectChessPeiceContainer);
		for (int i = 0; i <= 3; i++) {
			sf::RectangleShape& listItem = listItems[i];
			window.draw(listItem);
		}
		for (int i = 0; i <= 3; i++) {
			sf::Text& listItemText = listItemTexts[i];
			window.draw(listItemText);
		}
	}
};

