#include "Game.h"
#include<iostream>

Game::Game()
{
	srand(time(NULL));
}

Game::~Game()
{
}

void Game::Init(const char * title, int xPos, int yPos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{


		std::cout << "Subsystems initialised!" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
			std::cout << "Renderer created!" << std::endl;


		}
		isRunning = true;
	}
	else {
		isRunning = false;
	}
	if (!IMG_Init(IMG_INIT_PNG) == 0)
	{

	}
	else
	{
		std::cout << IMG_GetError() << std::endl;
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");


	//m_emitter = new Dot(300,300,renderer);
	/*for (int i = 0; i < 100; i++)
	{
		m_particles.push_back(new Particle(300,300,renderer));
	}*/
	
	emitters.push_back(new Emitter(400,300,renderer));
	emitters.push_back(new Emitter(300, 300, renderer));
	emitters.push_back(new Emitter(200, 300, renderer));
	emitters.push_back(new Emitter(100, 300, renderer));
}

void Game::HandleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;

	case SDL_KEYDOWN:
		break;
	}

}

void Game::Update()
{
	//system("cls");

	fps.start();



	for (auto & p : m_particles)
	{
		p->update();

		if (p->isDead())
		{
			//m_particles.erase(std::remove(m_particles.begin(), m_particles.end(), p), m_particles.end());
			//delete p;
		}
	}

	for (auto &e : emitters)
	{
		e->update();
	}


	frame++;

	//If we want to cap the frame rate
	if ((cap == true) && (fps.getTicks() < 1000 / FRAMES_PER_SECOND))
	{
		//Sleep the remaining frame time
		SDL_Delay((1000 / FRAMES_PER_SECOND) - fps.getTicks());
	}
}

void Game::Draw()
{

	SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

	SDL_RenderClear(renderer);
	//this is where we draw stuff
	for (auto & p : m_particles)
	{
		
		p->draw();

	}
	for (auto &e : emitters)
	{
		e->draw();
	}
	SDL_RenderPresent(renderer);
}

void Game::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}

bool Game::Running()
{
	return isRunning;
}
