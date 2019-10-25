#pragma once

#include <SFML/Graphics.hpp>

#include <NEAT/Header Files/NEAT_Map.h>
#include <NEAT/Header Files/NEAT_Brain.h>

namespace neat
{
	struct Agent
	{
		Map map;
		Brain brain;
		float fitness;
		sf::Color color;
		sf::CircleShape circle;
		sf::Vector2f pos, vel, acc;
		bool dead, reached_goal, is_best;

		Agent();
		Agent get_copy();
		void move();
		void update();
		void calculate_fitness();
		void show(sf::RenderWindow& window);
	};
}