#include <iostream>

#include "Renderer.h"
#include "Random.h"
#include "Canvas.h"

int main(int, char**)
{
	std::cout << "Hello World!";

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray Tracing", 400, 300);
	Canvas canvas(400, 300, renderer);


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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++)
		{
			canvas.DrawPoint({ random(0, 400), random(0, 300) }, { random(0, 1), random(0, 1), random(0, 1), 1 });
		}

		canvas.Update();
		renderer.PresentCanvas(canvas);
	}
	renderer.Shutdown();

	return 0;
}