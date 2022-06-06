#include "Swarm.h"

namespace game {

	Swarm::Swarm()
	{
		m_particles.resize(Swarm::NPARTICLES);
	}

	Swarm::~Swarm()
	{
	}

	void Swarm::update()
	{
		for (auto &particle : m_particles)
		{
			particle.update();
		}
	}

}