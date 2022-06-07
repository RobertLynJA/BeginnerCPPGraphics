#include "Swarm.h"

namespace game {

	Swarm::Swarm() : lastTime(0)
	{
		m_particles.resize(Swarm::NPARTICLES);
	}

	Swarm::~Swarm()
	{
	}

	void Swarm::update(int elapsed)
	{
		int interval = elapsed - lastTime;

		for (auto &particle : m_particles)
		{
			particle.update(interval);
		}

		lastTime = elapsed;
	}

}