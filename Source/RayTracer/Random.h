#pragma once
#include <stdlib.h>
#include <utility>
#include <random>

inline void seedRandom(unsigned int seed)
{
	srand(seed);
}

// returns a random float from 0 to 1
inline float random01()
{
	return rand() / (float)RAND_MAX;
}

inline float random(float min, float max)
{
	if (min > max) std::swap(min, max);
	return (random01() * (max - min) + min);
}