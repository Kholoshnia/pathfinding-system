#pragma once

#include <SFML/Graphics.hpp>

namespace ql
{
	extern int width, height;
	extern sf::Vector2i map_size;

	struct Agent
	{
		sf::Vector2f pos;
		sf::RectangleShape rect;

		Agent();
		void update(const int n);
		void show(sf::RenderWindow& window);
	};
}