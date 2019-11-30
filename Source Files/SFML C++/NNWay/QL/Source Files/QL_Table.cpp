#include <QL/Header Files/QL_Table.h>

ql::Table::Table()
{
	R.resize(map_size.y * map_size.y);
	for (auto& el : R)
		el.resize(map_size.y * map_size.y);

	Q.resize(map_size.y * map_size.y);
	for (auto& el : Q)
		el.resize(map_size.y * map_size.y);

	for (int state_y = 0; state_y < map_size.y * map_size.y; state_y++)
		for (int action_x = 0; action_x < map_size.x * map_size.x; action_x++)
			Q[state_y][action_x] = 0;

	srand((unsigned int)time(NULL));

	for (int state_y = 0; state_y < map_size.y * map_size.y; state_y++)
		for (int action_x = 0; action_x < map_size.x * map_size.x; action_x++)
			R[state_y][action_x] = -1;

	for (int y = 0; y < map_size.y; y++)
	{
		for (int x = 0; x < map_size.x; x++)
		{
			int a;
			if (map_size.y * y + x == 146)
				a = 0;

			if (x - 1 >= 0)
				if (map->map_markup[y][x - 1] == 'B')
					R[map_size.y * y + x][map_size.y * y + x - 1] = 0;
				else if (map->map_markup[y][x - 1] == 'F')
					R[map_size.y * y + x][map_size.y * y + x - 1] = goal_reward;

			if (x + 1 < map_size.x)
				if (map->map_markup[y][x + 1] == 'B')
					R[map_size.y * y + x][map_size.y * y + x + 1] = 0;
				else if (map->map_markup[y][x + 1] == 'F')
					R[map_size.y * y + x][map_size.y * y + x + 1] = goal_reward;

			if (y - 1 >= 0)
				if (map->map_markup[y - 1][x] == 'B')
					R[map_size.y * y + x][map_size.y * (y - 1) + x] = 0;
				else if (map->map_markup[y - 1][x] == 'F')
					R[map_size.y * y + x][map_size.y * (y - 1) + x] = goal_reward;

			if (y + 1 < map_size.y)
				if (map->map_markup[y + 1][x] == 'B')
					R[map_size.y * y + x][map_size.y * (y + 1) + x] = 0;
				else if (map->map_markup[y + 1][x] == 'F')
					R[map_size.y * y + x][map_size.y * (y + 1) + x] = goal_reward;

			if (map->map_markup[y][x] == 'F')
			{
				R[map_size.y * y + x][map_size.y * y + x] = goal_reward;
				goal_state = map_size.y * y + x;
			}
		}
	}
}

void ql::Table::choose_an_action()
{
	int possible_action = get_random_action(0, map_size.x * map_size.x - 1);

	if (R[state][possible_action] >= 0)
	{
		Q[state][possible_action] = (long long)R[state][possible_action] + (long long)gamma * maximum(possible_action, false);
		state = possible_action;
	}
}

void ql::Table::episode(int init_state)
{
	state = init_state;
	if (state != goal_state)
		do
		{
			choose_an_action();
			agent->update(state);
		} while (state == goal_state);
	for (int i = 0; i < map_size.x * map_size.y; i++)
		choose_an_action();
}

int ql::Table::inference_best_action(int now_state)
{
	int best_action = 0;
	long long temp_max_q = 0;

	for (int i = 0; i < map_size.x * map_size.y; ++i)
		if (Q[now_state][i] > temp_max_q)
		{
			temp_max_q = Q[now_state][i];
			best_action = i;
		}

	return best_action;
}

long long ql::Table::maximum(int st, bool return_index_only)
{
	int winner = 0;
	bool found_new_winner = false, done = false;

	do
	{
		found_new_winner = false;
		for (int i = 0; i < map_size.x * map_size.y; i++)
			if ((i < winner) || (i > winner))
				if (Q[st][i] > Q[st][winner])
				{
					winner = i;
					found_new_winner = true;
				}

		if (found_new_winner == false)
			done = true;
	} while (done == false);

	if (return_index_only == true) return winner;
	else return Q[st][winner];
}

int ql::Table::get_random_action(int lower_bound, int upper_bound)
{
	int act;
	bool choice_is_valid = false;

	do
	{
		act = lower_bound + (((upper_bound - lower_bound) + 1) * static_cast<int>(rand()) / (static_cast<int>(RAND_MAX) + 1));
		if (R[state][act] > -1) choice_is_valid = true;
	} while (choice_is_valid == false);

	return act;
}