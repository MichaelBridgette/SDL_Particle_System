#include "Particle.h"

Particle::Particle(int x, int y, SDL_Renderer * renderer)
{
	m_rend = renderer;
	m_posX = x;
	m_posY = y;

	float speed = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (5.f))) + 0.2f;
	float angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (2 * acos(-1))));

	m_velX = speed * cos(angle);
	m_velY = speed * sin(angle) - 4.f;

	srcrect = { 0, 0, 10, 10 };
	dstrect = { 0, 0, 10, 10 };

	m_frame = 0;
	alpha = 255;
	color = { 255, 0, 0, alpha };
	dead = false;
}

Particle::~Particle()
{

}

void Particle::draw()
{
	dstrect = { (int)m_posX, (int)m_posY, 5, 5 };
	SDL_SetRenderDrawColor(m_rend, color.r, color.g, color.b, alpha);
	SDL_RenderFillRect(m_rend, &dstrect);
}

bool Particle::isDead()
{
	return dead;
}

void Particle::update()
{
	m_frame++;

	m_velY += 0.3f;

	m_posX += m_velX;
	m_posY += m_velY;


	Uint8 decrement = 15;

	if (m_frame > 30)
	{
		//dead = true;
		if (alpha > 0)
		{
			//alpha -= alpha < decrement ? alpha : decrement;
			if (alpha <= decrement)
			{
				alpha = 0;
				dead = true;
			}
			else
			{
				alpha -= decrement;
			}
		}
	}
}
