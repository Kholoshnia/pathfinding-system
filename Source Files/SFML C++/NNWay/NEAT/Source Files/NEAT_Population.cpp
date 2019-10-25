#include <NEAT/Header Files/NEAT_Population.h>

neat::Population::Population()
{
	srand(clock());
	color = sf::Color(rand() & 255, rand() & 255, rand() & 255);
	reached_the_goal = false;
	fitness_sum = 0;
	agents.resize(population_quantity);
	if (layers_quantity != 1)
		for (auto& el : agents)
			el.color = color;
	gen = 1;
	min_step = direction_array_size;
	best_agent = 0;
	after_reach = 0;
}

neat::Agent neat::Population::select_parent()
{
	float random = float(rand()) / (float(RAND_MAX / fitness_sum));
	float running_sum = 0;
	for (auto& agent : agents)
	{
		running_sum += agent.fitness;
		if (running_sum > random)
			return agent;
	}
	Agent null;
	return null;
}

bool neat::Population::all_agents_dead()
{
	for (auto& agent : agents)
		if (!agent.dead && !agent.reached_goal)
			return false;
	return true;
}

void neat::Population::mutate()
{
	for (int i = 1; i < agents.size(); ++i)
		agents[i].brain.mutate();
}

void neat::Population::update()
{
	for (auto& agent : agents)
	{
		if (agent.brain.step > min_step)
			agent.dead = true;
		else
			agent.update();
		if (agent.reached_goal)
			reached_the_goal = true;
	}
}

void neat::Population::set_best_agent()
{
	float max = 0;
	int max_index = 0;
	for (int i = 0; i < agents.size(); ++i)
	{
		if (agents[i].fitness > max)
		{
			max = agents[i].fitness;
			max_index = i;
		}
	}
	best_agent = max_index;
	if (agents[best_agent].reached_goal)
		min_step = agents[best_agent].brain.step;
}

void neat::Population::calculate_fitness()
{
	for (auto& agent : agents)
		agent.calculate_fitness();
}

void neat::Population::natural_selection()
{
	calculate_fitness_sum();
	std::vector<Agent>new_agents;
	new_agents.resize(agents.size());
	set_best_agent();
	new_agents[0] = agents[best_agent].get_copy();
	new_agents[0].is_best = true;
	for (int i = 1; i < agents.size(); ++i)
	{
		Agent parent = select_parent();
		new_agents[i] = parent.get_copy();
	}
	agents = new_agents;
	if (layers_quantity != 1)
		for (auto& el : agents)
			el.color = color;
	gen++;
}

void neat::Population::calculate_fitness_sum()
{
	fitness_sum = 0;
	for (auto& agent : agents)
		fitness_sum += agent.fitness;
}

void neat::Population::show(sf::RenderWindow& window)
{
	for (int i = 1; i < agents.size(); ++i)
		agents[i].show(window);
	agents[0].show(window);
}