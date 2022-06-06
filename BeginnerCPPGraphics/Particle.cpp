#include "Particle.h"
#include <stdlib.h>

namespace game {

	Particle::Particle()
	{
		x = ((2.0 * rand()) / RAND_MAX) - 1;
		y = ((2.0 * rand()) / RAND_MAX) - 1;

		xSpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
		ySpeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	}

	Particle::~Particle()
	{
	}

	void Particle::update()
	{
		x += xSpeed;
		y += ySpeed;

		if (x <= -1.0 || x >= 1.0) {
			xSpeed = -xSpeed;
		}

		if (y <= -1.0 || y >= 1.0) {
			ySpeed = -ySpeed;
		}
	}

}