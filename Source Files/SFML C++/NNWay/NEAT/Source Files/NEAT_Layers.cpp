#include "NEAT/Header Files/NEAT_Layers.h"

neat::Layers::Layers() { populations.resize(layers_quantity); }

bool neat::Layers::all_populations_dead()
{
	for (auto& el : populations)
		if (!el.all_agents_dead())
			return false;
	return true;
}

neat::Population neat::Layers::get_best_population()
{
	float max = 0;
	int max_index = 0;
	for (int i = 0; i < populations.size(); ++i)
		if (populations[i].agents[populations[i].best_agent].fitness > max)
		{
			max = populations[i].agents[populations[i].best_agent].fitness;
			max_index = i;
		}
	return populations[max_index];
}

void neat::Layers::update()
{
	for (int i = 0; i < populations.size(); ++i)
		threads.emplace_back(&Layers::update_selected, this, i);
	for (int i = 0; i < threads.size(); ++i)
		if (threads[i].joinable())
		{
			threads[i].join();
			threads.erase(threads.begin() + i);
		}
}

void neat::Layers::update_selected(const int& i)
{
	if (populations[i].all_agents_dead())
	{
		populations[i].calculate_fitness();
		populations[i].natural_selection();
		populations[i].mutate();
		if (populations[i].reached_the_goal) populations[i].after_reach++;
	}
	else
		populations[i].update();
}

void neat::Layers::show(sf::RenderWindow& window)
{
	for (auto& el : populations)
		el.show(window);
}