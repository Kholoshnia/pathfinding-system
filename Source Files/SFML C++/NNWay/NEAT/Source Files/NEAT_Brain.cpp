#include "NEAT/Header Files/NEAT_Brain.h"

neat::Brain::Brain()
{
	step = 0;
	directions.resize(direction_array_size);
	randomize();
}

void neat::Brain::randomize()
{
	for (auto& el : directions)
		movement(el);
}

neat::Brain neat::Brain::clone()
{
	Brain clone;
	for (int i = 0; i < directions.size(); ++i)
		clone.directions[i] = directions[i];
	return clone;
}

void neat::Brain::mutate()
{
	for (auto& el : directions)
	{
		float randn = float(rand()) / (float(RAND_MAX));
		if (randn < mutation_rate)
			movement(el);
	}
}

void neat::Brain::movement(sf::Vector2f& obj)
{
	obj.x = static_cast<float>(cos(-180.0f + float(rand()) / (float(RAND_MAX / 360.0f)) * M_PI / 180.0f));
	obj.y = static_cast<float>(sin(-180.0f + float(rand()) / (float(RAND_MAX / 360.0f)) * M_PI / 180.0f));
}