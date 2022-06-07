#pragma once

namespace game {

	struct Particle
	{
		double x;
		double y;
		double speed;
		double direction;

		Particle();
		~Particle();
		void update(int interval);
	};

}

