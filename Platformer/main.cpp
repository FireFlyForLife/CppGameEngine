#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Input.h"
#include <functional>
#include "World.h"
#include "Point.h"
#include "TextureManager.h"
#include "Globals.h"
#include "Renderer.h"
#include "UI_element.h"
#include "Rock.h"
#include "Player.h"
#include "FollowingCamera.h"
#include "EntityWall.h"
#include "Physics.h"
#include "PhysicsPlayer.h"

using namespace GameEngine;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Loads individual image as texture
SDL_Texture* loadTexture(std::string path);

void waitForKeyPress();
ent_ptr addToWorld(Entity* entity);
ent_ptr addToWorld(UI_element* entity);
void addToWorld(int x, int y, Tile* entity);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

//To be deleted
GameEngine::World* game_world = nullptr;
GameEngine::Renderer* renderer = nullptr;
GameEngine::PhysicsEngine* physics_engine = nullptr;
TTF_Font* font = nullptr;

bool init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL Error: %s\n" << SDL_GetError() << std::endl;
		return false;
	}

	//Set texture filtering to linear
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
	}

	//Create window
	gWindow = SDL_CreateWindow("Platformer!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Global::SCREEN_WIDTH, Global::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
		return false;
	}

	//Initialize text rendering
	if (TTF_Init() == -1) {
		std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	Global::texture_manager.setupDefault(gRenderer);
	Global::texture_manager.add(loadTexture("Art/Robot.png"), "player");
	Global::texture_manager.add(loadTexture("Art/Grass.png"), "grass");
	Global::texture_manager.add(loadTexture("Art/Rock.png"), "rock");
	Global::texture_manager.add(loadTexture("Art/Preview.png"), "preview");

	font = TTF_OpenFont("AlphaFridgeMagnets.ttf", 24);

	return success;
}

void close()
{
	//delete font
	TTF_CloseFont(font);

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	delete game_world;
	delete renderer;
	delete physics_engine;

	game_world = nullptr;
	renderer = nullptr;
	physics_engine = nullptr;
	font = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

//function from Lazy Foo's tutorials
SDL_Texture* loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image %s! SDL_image Error: %s\n" << path.c_str() << IMG_GetError() << std::endl;
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			std::cout << "Unable to create texture from %s! SDL Error: %s\n" << path.c_str() << SDL_GetError() << std::endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}

//utility methods for adding to the game_world
ent_ptr addToWorld(Entity* entity) {
	return game_world->entity_list->add( entity );
}

ent_ptr addToWorld(UI_element* ui) {
	return game_world->UI_elements->add(ui);
}

void addToWorld(int x, int y, Tile* tile) {
	Point p{ x, y };
	game_world->map->set(tile, p);
}

void waitForKeyPress() {
	std::cout << "Press Enter to continue..." << std::endl;
	char c;
	std::cin >> c;
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl; waitForKeyPress();
		return 1;
	}

	//Load media
	if (!loadMedia())
	{
		std::cout << "Failed to load media!" << std::endl; waitForKeyPress();
		return 1;
	}
	game_world = new World();
	renderer = new Renderer(gRenderer);
	physics_engine = new PhysicsEngine(game_world);
	physics_engine->gravity = Vector2(0, -0.5f);

	int scale = game_world->map->tile_scale;

	//add some grass to the background
	for (int x = 0; x < game_world->map->width; x++) {
		for (int y = 0; y < game_world->map->height; y++) {
			Tile* tile = new Tile("grass");
			game_world->map->set(tile, Point(x, y));
		}
	}

	//create some walls in the map
	for (int x = 0; x < 10; x++) {
		for (int y = 20; y < 20 + 15; y++) {
			Tile* rock = new Rock();
			addToWorld(x, y, rock);
		}
	}
	for (int x = 17; x < 17 + 10; x++) {
		for (int y = 5; y < 5 + 19; y++) {
			Tile* rock = new Rock();
			addToWorld(x, y, rock);
		}
	}
	for (int x = 0; x < 20; x++) {
		EntityWall* ent_wall = new EntityWall(x*scale, 10 * scale, "preview");
		addToWorld(ent_wall);
	}

	

	//add entities to the world
	PhysicsPlayer* player = new PhysicsPlayer(
		scale * 5, 
		scale * 2, 
		"player");
	ent_ptr player_ptr = addToWorld(player);

	FollowingCamera* camera = new FollowingCamera(player_ptr);
	camera->offset = Point(Global::SCREEN_WIDTH / 2 - game_world->map->tile_scale / 2, Global::SCREEN_HEIGHT / 2 - game_world->map->tile_scale / 2 );
	ent_ptr camera_ptr = addToWorld(camera);
	game_world->camera = std::static_pointer_cast<Camera>( camera_ptr );

	EntityWall* ent_wall = new EntityWall(
		Global::SCREEN_WIDTH / 2 - game_world->map->tile_scale / 2 + 2 * scale,
		Global::SCREEN_HEIGHT / 2 - game_world->map->tile_scale / 2,
		"preview");
	addToWorld(ent_wall);

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

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
				//let my input handler dispatch the events
				GameEngine::handle_SDL_Event(&e);
			}
		}

		//Update all active GameObjects
		game_world->Update();

		//handle collision
		physics_engine->update();

		//call lateupdate
		game_world->LateUpdate();

		//Clear screen
		SDL_RenderClear(gRenderer);

		//let the my renderer render it to a buffer
		renderer->renderWorld(*game_world);

		//Update screen
		SDL_RenderPresent(gRenderer);
	}

	//Free resources and close SDL
	close();

	return 0;
}