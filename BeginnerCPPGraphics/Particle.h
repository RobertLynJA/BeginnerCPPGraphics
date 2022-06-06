#pragma once

namespace game {

	struct Particle
	{
		double x;
		double y;

		Particle();
		~Particle();
		void update();
	};

}

