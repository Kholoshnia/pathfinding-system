#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <thread>
#include <sstream>
#include <functional>

#include "Population.hpp"

class Layers
{
public:
    int best_population;
    std::vector<Population> populations;
    std::vector<std::shared_ptr<sf::Thread>> threads;

    Layers();

    bool all_populations_dead();

    void set_best_population();

    void update();

    void update_selected(const int &i);

    void show(sf::RenderWindow &window);
};