#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <sstream>
#include <vector>
#include <thread>

#include <NEAT/Header Files/NEAT_Population.h>

extern int fps;

namespace neat
{
	extern int layers_quantity;

	struct Layers
	{
		std::vector<std::shared_ptr<sf::Thread>> threads;
		std::vector<Population> populations;

		Layers();
		bool all_populations_dead();
		Population get_best_population();
		void update();
		void update_selected(const int& i);
		void show(sf::RenderWindow& window);
	};
}