#ifndef PARTICLE_H
#define PARTICLE_H

#include <SDL.h>
#include<SDL_image.h>
#include <stdlib.h>
#include <time.h>  
#include <iostream>

const int MAX_PARTICLES = 1;

static int particleCount = 0;

class Particle 
{
public:
	Particle(int x, int y, SDL_Renderer * renderer);
	~Particle();

	void draw();
	bool isDead();

	void update();

private:
	float m_posX, m_posY;
	float m_velX, m_velY;
	int m_frame;

	SDL_Renderer * m_rend;
	SDL_Rect srcrect;
	SDL_Rect dstrect;

	SDL_Rect r;

	SDL_Color color;
	Uint8 alpha;

	bool dead;
};

#endif // !PARTICLE_H

