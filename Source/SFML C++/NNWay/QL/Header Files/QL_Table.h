#pragma once

#include <SFML/Graphics.hpp>

#include <ctime>
#include <vector>
#include <iostream>

#include <QL/Header Files/QL_Map.h>
#include <QL/Header Files/QL_Agent.h>

namespace ql
{
	extern std::shared_ptr<Agent> agent;
	extern int finish_state;
	extern std::shared_ptr<Map> map;
	extern long long int finish_reward;

	struct Table
	{
		int state, action;
		const float gamma = 0.8f;
		std::vector<std::vector<long long int>> R;
		std::vector<std::vector<long long int>> Q;

		Table();
		void choose_an_action();
		void episode(int init_state);
		int inference_best_action(int now_state);
		long long maximum(int st, bool return_index_only);
		int get_random_action(int lower_bound, int upper_bound);
	};
}