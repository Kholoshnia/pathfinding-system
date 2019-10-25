#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

namespace neat
{
	extern int direction_array_size;

	struct Brain
	{
		int step;
		std::vector<sf::Vector2f>directions;

		Brain();
		Brain clone();
		void mutate();
		void randomize();
	};
}