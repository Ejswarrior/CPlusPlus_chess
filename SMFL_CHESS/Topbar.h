#pragma once
#include <SFML/Graphics.hpp>

class Topbar
{	
	private: 
		sf::RectangleShape topbarContainer;

	public: 
		Topbar(){
			topbarContainer.setPosition(sf::Vector2f(0, 0));
			topbarContainer.setSize(sf::Vector2f(1280, 75));
		}

		void draw(sf::RenderWindow& window) {
			window.draw(topbarContainer);
		}
};

