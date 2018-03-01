#include "../SDL/include/SDL.h"
#pragma comment(lib, "../SDL/libx86/SDL2.lib")
#pragma comment(lib, "../SDL/libx86/SDL2main.lib")
#include<stdio.h>
#include <iostream>


int main(int argc, char *argv[]) {
	//Declare a pointer
	SDL_Rect rectangle;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	//variables
	bool quit = false;
	bool changex = false;
	bool changey = false;
	int x = 0;
	int y = 0;



	SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2
	//Create rectangle
	/*rectangle.x = x;
	rectangle.y = y;*/
	
	rectangle.w = 100;
	rectangle.h = 100;

	// Create an application window with the following settings:
	window = SDL_CreateWindow("Homework Window_Game0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

	if (window == NULL) { // Check that the window was successfully created

		printf("Could not create window: %s\n", SDL_GetError());
		return 1;
	}

	renderer = SDL_CreateRenderer(window, -1, 0); /* We must call SDL_CreateRenderer in order for draw calls to affect this window. */

	while (!quit) {  //close button
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}

		}


		/*//close button
		bool isRunning = true;


		while (isRunning) {

			while (SDL_PollEvent(&ev) != 0) { //ask &ev
				if (ev.type == SDL_QUIT)
					isRunning = false;
			}

			SDL_UpdateWindowSurface(window);
		}*/

		rectangle.x = x;
		rectangle.y = y;

		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255); /* Select the color for drawing. It is set to red here. */
		SDL_RenderClear(renderer); /* Clear the entire screen to our selected color. */
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rectangle); //fill a rectangle on the current rendering target with the drawing color
		SDL_RenderPresent(renderer); /* Up until now everything was drawn behind the scenes.
		IMPORTANT, Use this function to update the screen with any rendering performed since the previous call. This will show the new, red contents of the window. */
		SDL_Delay(10); //Delay 10ms

		//Motion

		if (x < 440 && !changex) {
			x++;
		}
		else if (x >= 0) {
			x--;
			changex = true;
		}

		if (y < 380 && !changey) {
			y++;
		}
		else if (y >= 0) {
			y--;
			changey = true;
		}
		if (x == 0) {
			changex = false;
		}
		if (y == 0) {
			changey = false;
		}

	}
	SDL_DestroyRenderer(renderer); //destroy the rendering context for a window and free associated textures
	SDL_DestroyWindow(window); // Close and destroy the window
	SDL_Quit(); // Clean up

	return 0;
}





