#include <iostream>

#include "Renderer.h"
#include "Random.h"

int main(int, char**)
{
	std::cout << "Hello World!";

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray Tracing", 400, 300);

	seedRandom((unsigned int)time(nullptr));

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
	renderer.Shutdown();

	return 0;
}