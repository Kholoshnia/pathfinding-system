#pragma once

#include <SFML/Graphics.hpp>

namespace ql
{
	extern int map_size_x, map_size_y, width, height;

	struct Agent
	{
		sf::Vector2f pos;
		sf::RectangleShape rect;

		Agent();
		void update(const int n);
		void show(sf::RenderWindow& window);
	};
}