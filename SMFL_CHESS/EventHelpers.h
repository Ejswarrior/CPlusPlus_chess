#pragma once
#define EventHelpers
#include <SFML/Graphics.hpp>


bool clickedOnObject(sf::Vector2f objectPosition, sf::Vector2f objectSize, sf::Vector2f mouseClickPosition) {

	if (mouseClickPosition.x > objectPosition.x && mouseClickPosition.x < objectPosition.x + objectSize.x
		&& mouseClickPosition.y > objectPosition.y && mouseClickPosition.y < objectPosition.y + objectSize.y)
		return true;
	else return false;
}
