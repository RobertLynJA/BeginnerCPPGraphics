#pragma once

namespace game {

	struct Particle
	{
		double x;
		double y;
		double xSpeed;
		double ySpeed;

		Particle();
		~Particle();
		void update();
	};

}

