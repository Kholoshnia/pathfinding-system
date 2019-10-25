#include "NEAT/Header Files/NEAT_Brain.h"

neat::Brain::Brain()
{
	step = 0;
	directions.resize(direction_array_size);
	randomize();
}

void neat::Brain::randomize()
{
	for (auto& directions : directions)
	{
		float randomAngle = -180 + float(rand()) / (float(RAND_MAX / 360));
		directions.x = (float)cos(randomAngle * 3.14159265 / 180);
		directions.y = (float)sin(randomAngle * 3.14159265 / 180);
	}
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
	float mutationRate = 0.01f;
	for (auto& directions : directions)
	{
		float randn = float(rand()) / (float(RAND_MAX));
		if (randn < mutationRate)
		{
			float randomAngle = -180.0f + float(rand()) / (float(RAND_MAX / 360.0f));
			directions.x = cos(randomAngle * 3.14159265f / 180.0f);
			directions.y = sin(randomAngle * 3.14159265f / 180.0f);
		}
	}
}