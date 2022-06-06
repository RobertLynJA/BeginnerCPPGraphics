#pragma once

#include "Particle.h"
#include <vector>

namespace game {

	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		const std::vector<Particle> m_pParticles;
	public:
		Swarm();
		~Swarm();

		const std::vector<Particle>& getParticles() const { return m_pParticles; }
	};

}
