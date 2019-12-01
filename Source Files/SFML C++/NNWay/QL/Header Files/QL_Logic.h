#pragma once

#include <SFML/Graphics.hpp>

#include <sstream>
#include <fstream>

#include <Enums.h>

#include <QL/Header Files/QL_Map.h>
#include <QL/Header Files/QL_Table.h>
#include <QL/Header Files/QL_Agent.h>

extern bool from_image;
extern sf::Sprite loading;
extern int fps, width, height;

namespace ql
{
	extern std::shared_ptr<Map> map;
	extern std::shared_ptr<Table> table;
	extern std::shared_ptr<Agent> agent;

	extern sf::Text text[4];
	extern sf::Vector2i map_size;
	extern std::string image_path;
	extern std::fstream fout, fin;
	extern std::vector<int> initials;
	extern long long int goal_reward;
	extern int goal_state, repetitions;
	extern bool map_loaded, goal_loaded, around;

	void check_2d();
	void check_3d();
	void create_new_map_2d();
	void create_new_map_3d();
	void draw(sf::Event& event);
	void load_map_from_file_2d();
	void load_map_from_file_3d();
	void load_result_from_file_2d();
	void load_result_from_file_3d();
	void with_visualization_2d();
	void with_visualization_3d();
	void without_visualization_2d();
	void without_visualization_3d();
}