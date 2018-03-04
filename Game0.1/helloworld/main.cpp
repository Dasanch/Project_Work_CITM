#include "../SDL/include/SDL.h"
#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#include<stdio.h>
#include <iostream>

typedef struct
{
	int x;
	int y;
}position;


int main(int argv, char *argc[])
{
	position rect;
	rect.x = 240;
	rect.y = 180;

	position shoot;
	shoot.x = rect.x;
	shoot.y = rect.y;


	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return 1;
	}
	else
	{
		window = SDL_CreateWindow("Red Square", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			return 1;
		}
		else
		{
			SDL_Rect rectangle;
			rectangle.x = 240;
			rectangle.y = 180;
			rectangle.w = 160;
			rectangle.h = 120;

			SDL_Rect shootrect = {shoot.x, (shoot.y), 50, 20};

			renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 50, 100, 255, 255);

			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
			SDL_RenderFillRect(renderer, &shootrect);

			SDL_RenderClear(renderer);

			bool loop = true;

			while (loop)
			{
				SDL_Event event;
				if (SDL_PollEvent(&event) != 0)
				{
					switch (event.type)
					{
					case SDL_QUIT:
						loop = false;
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym)
						{
						case SDLK_UP:
							rectangle.y -= 15;
							break;
						case SDLK_DOWN:
							rectangle.y += 15;
							break;
						case SDLK_LEFT:
							rectangle.x -= 15;
							break;
						case SDLK_RIGHT:
							rectangle.x += 15;
							break;
						case SDLK_ESCAPE:
							loop = false;

						case SDLK_SPACE:
							shootrect.x = rectangle.x;
							shootrect.y = rectangle.y;
							while (shootrect.x <640) {
								SDL_SetRenderDrawColor(renderer, 50, 100, 255, 255);

								SDL_RenderClear(renderer);// Clear the entire screen to our selected color.

								SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
								SDL_RenderFillRect(renderer, &shootrect);

								shootrect.x += 1;

								SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
								SDL_RenderFillRect(renderer, &rectangle);

								SDL_RenderPresent(renderer);

							}

						}
					}
				}
				SDL_SetRenderDrawColor(renderer, 255, 50, 50, 255);
				SDL_RenderFillRect(renderer, &rectangle);
				SDL_RenderPresent(renderer);

				SDL_SetRenderDrawColor(renderer, 50, 100, 255, 255);
				SDL_RenderClear(renderer);
			}
		}
	}
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}