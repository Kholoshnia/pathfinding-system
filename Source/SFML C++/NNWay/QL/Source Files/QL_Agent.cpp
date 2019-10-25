#include <QL/Header Files/QL_Agent.h>

ql::Agent::Agent()
{
	rect.setFillColor(sf::Color::Yellow);
	rect.setSize(sf::Vector2f((float)(height / map_size_x), (float)(width / map_size_y)));
}

void ql::Agent::update(const int n)
{
	pos = sf::Vector2f((float)((n - map_size_x * (n / map_size_x)) * (width / map_size_y)), (float)((n / map_size_x) * (height / map_size_x)));
}

void ql::Agent::show(sf::RenderWindow& window)
{
	rect.setPosition(pos);
	window.draw(rect);
}
