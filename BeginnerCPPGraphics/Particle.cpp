#include "Particle.h"
#include <stdlib.h>

namespace game {

	Particle::Particle()
	{
		x = ((2.0 * rand()) / RAND_MAX) - 1;
		y = ((2.0 * rand()) / RAND_MAX) - 1;
	}

	Particle::~Particle()
	{
	}

	void Particle::update()
	{
		const auto speed = 0.01;

		x += speed;
		y += speed;
	}

}