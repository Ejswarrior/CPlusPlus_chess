#pragma once
#include <SFML/Graphics.hpp>

class SelectChessPieceMenu
{	
private: 
	sf::RectangleShape selectChessPeiceContainer;
	sf::RectangleShape bishopListItem;
	sf::RectangleShape QueenListItem;
	sf::Text bishopListItemText;

public:
	const sf::Vector2f listItemSize = sf::Vector2f(400 - 24, 400 / 4 - 12);
	sf::Vector2f getListItemPosition(int position) {
		int xPosition = 1280 / 2 - 200 + 12;
		int calculateYAmountDown = position != 0 ? ((400 / 4 - 6) * position) - 6 : 0;
		int yPostiton = 820 / 2 - 200 + (6 * position + 1) + calculateYAmountDown;

		return sf::Vector2f(xPosition, yPostiton);
	}

	SelectChessPieceMenu() {
		selectChessPeiceContainer.setSize(sf::Vector2f(400, 400));
		selectChessPeiceContainer.setPosition(sf::Vector2f(1280 / 2 - 200, 820 / 2 - 200));
		bishopListItem.setSize(listItemSize);
		bishopListItem.setPosition(getListItemPosition(0));
		bishopListItem.setFillColor(sf::Color::Blue);
		QueenListItem.setSize(listItemSize);
		QueenListItem.setPosition(getListItemPosition(1));
		QueenListItem.setFillColor(sf::Color::Blue);
	}


	void draw(sf::RenderWindow& window) {
		window.draw(selectChessPeiceContainer);
		window.draw(bishopListItem);
		window.draw(QueenListItem);
	}
};

