#ifndef EMITTER_H
#define EMITTER_H

#include<SDL.h>
#include<SDL_image.h>
#include"Particle.h"
#include<vector>
#include<algorithm>

class Emitter
{
public:

	Emitter(int x, int y,SDL_Renderer * renderer);
	~Emitter();

	void update();
	void draw();

private:
	//Particle* m_particles[MAX_PARTICLES];
	std::vector<Particle *> m_particles;
	void drawParticles();
	int m_posX, m_posY;
	SDL_Renderer * m_rend;

};

#endif // !EMITTER_H

