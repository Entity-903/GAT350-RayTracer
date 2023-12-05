#include <iostream>

#include "Renderer.h"
#include "Random.h"
#include "Canvas.h"
#include "Camera.h"
#include "Scene.h"
#include "Material.h"
#include "Sphere.h"

//#include <memory>

int main(int, char**)
{
	std::cout << "Hello World!";

	Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("Ray Tracing", 400, 300);
	Canvas canvas(400, 300, renderer);

	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene; // sky color could be set with the top and bottom color
	scene.SetCamera(camera);


	// create material
	auto material = std::make_shared<Lambertian>(color3_t{ 0, 0, 1 });

	// Create Objects -> Add to Scene
	for (int i = 0; i < 10; i++)
	{
		auto sphere = std::make_unique<Sphere>(random({ -25, -25, -50 }, { 25, 25, -10 }), random(1, 5), material);
		scene.AddObject(std::move(sphere));
	}

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
		scene.Render(canvas);
		canvas.Update();
		renderer.PresentCanvas(canvas);
	}
	renderer.Shutdown();

	return 0;
}