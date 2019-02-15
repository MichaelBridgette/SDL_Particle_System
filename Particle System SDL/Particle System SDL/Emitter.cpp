#include "Emitter.h"

Emitter::Emitter(int x, int y,SDL_Renderer * renderer)
{
	m_rend = renderer;

	m_posX = x;
	m_posY = y;
	
	/*for (int i = 0; i < MAX_PARTICLES; i++)
	{
		m_particles[i] = (new Particle(m_posX, m_posY, m_rend));
	}*/

	for (int i = 0; i < MAX_PARTICLES; i++)
	{
		m_particles.push_back (new Particle(m_posX, m_posY, m_rend));
	}
}

Emitter::~Emitter()
{
	//Delete particles
	/*for (int i = 0; i < MAX_PARTICLES; ++i)
	{
		delete m_particles[i];
	}*/

	for (int i = 0; i < m_particles.size(); ++i)
	{
		delete m_particles.at(i);
	}
}

void Emitter::update()
{
	/*for (int i = 0; i < MAX_PARTICLES; i++)
	{
		m_particles[i]->update();
	}*/

	for (int i = 0; i < m_particles.size(); i++)
	{
		m_particles.at(i)->update();
	}
	m_particles.push_back(new Particle(m_posX, m_posY, m_rend));
}

void Emitter::draw()
{
	drawParticles();
}

void Emitter::drawParticles()
{
	for (int i = 0; i < m_particles.size(); ++i)
	{
		//Delete and replace dead particles
		if (m_particles[i]->isDead())
		{
			delete m_particles.at(i);
			m_particles.erase(std::remove(m_particles.begin(), m_particles.end(), m_particles.at(i)), m_particles.end());
			
			//m_particles.push_back(new Particle(m_posX, m_posY, m_rend));
		}
	}
	std::cout << m_particles.size() << std::endl;
	//Show particles
	for (int i = 0; i < m_particles.size(); ++i)
	{
		m_particles.at(i)->draw();
	}
}
