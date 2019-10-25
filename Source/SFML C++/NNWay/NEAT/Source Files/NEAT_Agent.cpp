#include <NEAT/Header Files/NEAT_Agent.h>

neat::Agent::Agent()
{
	color = sf::Color::Black;
	this->map = map;
	fitness = 0;
	dead = false;
	reached_goal = false;
	is_best = false;
	pos = map.dot_pos;
	vel = sf::Vector2f(0, 0);
	acc = sf::Vector2f(0, 0);
	circle.setRadius(4);
}

neat::Agent neat::Agent::get_copy()
{
	Agent copy;
	copy.brain = brain.clone();
	return copy;
}

void neat::Agent::move()
{
	if (brain.directions.size() > brain.step)
	{
		acc = brain.directions[brain.step];
		brain.step++;
	}
	else dead = true;
	if (abs(vel.x + acc.x) < 5) vel.x += acc.x;
	if (abs(vel.y + acc.y) < 5) vel.y += acc.y;
	pos += vel;
}

void neat::Agent::update()
{
	if (!dead && !reached_goal)
	{
		move();
		if (map.touched(pos))
			dead = true;
		else if (map.dist(pos) < map.goal_r)
			reached_goal = true;
	}
}

void neat::Agent::calculate_fitness()
{
	if (reached_goal)
		fitness = 100000.0f / float(brain.step * brain.step);
	else
		fitness = 1.0f / (map.dist(pos) * map.dist(pos));
}

void neat::Agent::show(sf::RenderWindow& window)
{
	circle.setPosition(pos.x, pos.y);
	is_best ? circle.setFillColor(sf::Color::Green) : circle.setFillColor(color);
	window.draw(circle);
}