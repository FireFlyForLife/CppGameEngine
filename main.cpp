/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Input.h"
#include <functional>
#include "World.h"
#include "Point.h"

using namespace GameEngine;

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

const int texturesize = 16;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;
GameEngine::World game_world;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture("Art/Maybe_Grass.png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
}

void close()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

void lalala(GameEngine::KeyClickArgs* args, int i) {
	SDL_Log(std::to_string(args->down).c_str());
	SDL_Log(std::to_string(args->scan_code).c_str());
}

void mouseLis(MouseClickArgs* args, int i) {
	std::string cord = std::to_string(args->point.x) + "," + std::to_string(args->point.y);
	SDL_Log(cord.c_str());
	SDL_Log(std::to_string(args->down).c_str());
	SDL_Log(std::to_string(args->scan_code).c_str());
}

void mouseMov(MouseMoveArgs* args, int i) {
	SDL_Log(std::to_string(args->dragging).c_str());
	std::string cord = std::to_string(args->point.x) + "," + std::to_string(args->point.y);
	SDL_Log(cord.c_str());
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			Point p{ 4 ,3 };
			printf(p.toString().c_str());

			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			decltype(GameEngine::keyClickListeners)::callbackType func = lalala;
			decltype(mouseClickListeners)::callbackType mfunc = mouseLis;
			/*keyUpListeners.add(func);
			keyDownListeners.add(func);
			mouseDownListeners.add(mfunc);
			mouseUpListeners.add(mfunc);*/
			keyUpListeners.add( func);
			keyDownListeners.add(func);
			mouseDownListeners.add(mfunc);
			mouseUpListeners.add(mfunc);
			decltype(mouseMoveListeners)::callbackType mofunc = mouseMov;
			//mouseMoveListeners.add(mofunc);
			int mofunc_id = mouseMoveListeners.add(mofunc);
			//mouseMoveListeners.remove(mofunc_id);

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else {
						GameEngine::handle_SDL_Event(&e);
					}
				}

				//Clear screen
				SDL_RenderClear(gRenderer);

				//Render texture to screen
				for (int x = 0; x < SCREEN_WIDTH; x += texturesize) {
					for (int y = 0; y < SCREEN_HEIGHT; y += texturesize) {
						SDL_Rect rect = { x, y, texturesize, texturesize };
						SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
					}
				}
				//SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

				//Update screen
				SDL_RenderPresent(gRenderer);
			}
		}
	}

	//Free resources and close SDL
	close();

	return 0;
}