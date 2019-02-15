#pragma once
#include<SDL.h>
#include<iostream>
#include"SDL_image.h"
#include "Emitter.h"
#include <algorithm>    // std::remove_if
#include"Timer.h"

const int FRAMES_PER_SECOND = 240;

class Game {
public:
	Game();
	~Game();
	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

	void HandleEvents();
	void Update();
	void Draw();
	void Clean();

	bool Running();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

	std::vector<Particle *> m_particles;


	std::vector<Emitter *> emitters;


	//Keep track of the current frame
	int frame = 0;

	//Whether or not to cap the frame rate
	bool cap = true;

	//The frame rate regulator
	Timer fps;
};
