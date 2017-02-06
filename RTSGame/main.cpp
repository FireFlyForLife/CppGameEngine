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
#include "Player.h"
#include "Camera.h"
#include "MoveableCamera.h"
#include "Pathfinder.h"
#include "Rock.h"
#include "Unit.h"
#include "Spaceport.h"
#include "UnitController.h"
#include "Text_UI_element.h"
#include "Enemy.h"
#include "HealthBar.h"
#include "ResourceRock.h"
#include "ExplosiveEnemy.h"
#include "SpawnHole.h"
#include "PlacementManager.h"
#include "Tower.h"
#include "ExplosiveTower.h"
#include "Bomb.h"
#include "Worker.h"

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
void addToWorld(Entity* entity);
void addToWorld(UI_element* entity);
void addToWorld(int x, int y, Tile* entity);

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

//To be deleted
GameEngine::World* game_world = nullptr;
GameEngine::Renderer* renderer = nullptr;
Animation* expl_ani = nullptr;
TTF_Font* font = nullptr;

//non-owning pointers
PlacementManager* placement = nullptr;
Spaceport* base = nullptr;

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
	gWindow = SDL_CreateWindow("RTS: Explosion!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Global::SCREEN_WIDTH, Global::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
	Global::texture_manager.add(loadTexture("Art/Maybe_Grass.png"),		"grass");
	Global::texture_manager.add(loadTexture("Art/Little_Player.png"),	"player");
	Global::texture_manager.add(loadTexture("Art/Point.png"),			"point");
	Global::texture_manager.add(loadTexture("Art/Rock.png"),			"rock");
	Global::texture_manager.add(loadTexture("Art/Robot.png"),			"robot");
	Global::texture_manager.add(loadTexture("Art/Space_Port.png"),		"space_port");
	Global::texture_manager.add(loadTexture("Art/Selection_Rect.png"),	"selection_rectangle");
	Global::texture_manager.add(loadTexture("Art/Enemy.png"),			"enemy");
	Global::texture_manager.add(loadTexture("Art/Resource_Rock.png"),	"resource_rock");
	Global::texture_manager.add(loadTexture("Art/Hole.png"),			"hole");
	Global::texture_manager.add(loadTexture("Art/Bottom_UI.png"),		"bottom_UI");
	Global::texture_manager.add(loadTexture("Art/Tower.png"),			"tower");
	Global::texture_manager.add(loadTexture("Art/Tower_2.png"),			"tower2");
	Global::texture_manager.add(loadTexture("Art/Worker.png"),			"worker");
	Global::texture_manager.add(loadTexture("Art/Preview.png"),			"preview");
	Global::texture_manager.add(loadTexture("Art/Bomb.png"),			"bomb");

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
	delete expl_ani;

	game_world = nullptr;
	renderer = nullptr;
	expl_ani = nullptr;
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
void addToWorld(Entity* entity) {
	game_world->entity_list->entities.push_back(std::shared_ptr<Entity>(entity));
}

void addToWorld(UI_element* ui) {
	game_world->UI_elements->entities.push_back(std::shared_ptr<Entity>(ui));
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

//when the player presses a button, we give a entity to the PlacementManager to prepare placing the entity
void OnKeyPress(KeyClickArgs* args, int) {
	int resources = base->getResources();
	if (args->scan_code == SDL_SCANCODE_B && resources >= 10) {
		ExplosiveTower* tower = new ExplosiveTower(0, 0, *expl_ani, "tower");
		placement->prepare(tower);
		base->addResources(-10);
	}else if (args->scan_code == SDL_SCANCODE_N && resources >= 50) {
		Bomb* bomb = new Bomb(0, 0, *expl_ani);
		placement->prepare(bomb);
		base->addResources(-50);
	}else if (args->scan_code == SDL_SCANCODE_M && resources >= 15) {
		Worker* worker = new Worker(0, 0, "worker", base);
		placement->prepare(worker);
		base->addResources(-15);
	}
}

int main(int argc, char* args[])
{
	//Start up SDL and create window
	if (!init())
	{
		std::cout << "Failed to initialize!" << std::endl;
		waitForKeyPress();
		return 1;
	}

	//Load media
	if (!loadMedia())
	{
		std::cout << "Failed to load media!" << std::endl;
		waitForKeyPress();
		return 1;
	}
	game_world = new World();
	renderer = new Renderer(gRenderer);

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
		for (int y = 0; y < 10; y++) {
			Tile* rock = new Rock();
			addToWorld(x, y, rock);
		}
	}
	for (int x = 0; x < 10; x++) {
		for (int y = 20; y < 20+15; y++) {
			Tile* rock = new Rock();
			addToWorld(x, y, rock);
		}
	}
	for (int x = 17; x < 17+10; x++) {
		for (int y = 5; y < 5+19; y++) {
			Tile* rock = new Rock();
			addToWorld(x, y, rock);
		}
	}


	//setup explosion animation for all exploding actors
	SDL_Texture* expl_texture = loadTexture("Art/Explosion.ani.png");
	Point frame_size(64, 64);
	expl_ani = new Animation(expl_texture, frame_size, 100);

	//add entities to the world
	Player* player = new Player(scale*4, scale*17, "player");
	addToWorld(player);

	Camera* camera = new MoveableCamera(0, 0);
	game_world->camera = camera;
	addToWorld(camera);

	UnitController* unit_controller = new UnitController(game_world);
	addToWorld(unit_controller);
	
	Unit* robot = new Unit(scale*6, scale*14, "robot");
	addToWorld(robot);
	unit_controller->addUnit(robot);

	Text_UI_element* text = new Text_UI_element(100, 0, font, "0", "Resources: ");
	addToWorld(text);

	ResourceRock* r_rock = new ResourceRock(scale * 2, scale * 13);
	addToWorld(r_rock);

	ResourceRock* r_rock_0 = new ResourceRock(scale * 4, scale * 11);
	addToWorld(r_rock_0);

	ResourceRock* r_rock_1 = new ResourceRock(scale * 1, scale * 15);
	addToWorld(r_rock_1);

	SpawnHole* hole = new SpawnHole(scale * 30, scale * 6, *expl_ani);
	addToWorld(hole);
	SpawnHole* hole_2 = new SpawnHole(scale * 30, scale * 22, *expl_ani);
	addToWorld(hole_2);

	UI_element* bottom_UI = new UI_element(Global::SCREEN_WIDTH * 0.5 - 192*0.5, Global::SCREEN_HEIGHT - 48, "bottom_UI");
	addToWorld(bottom_UI);

	Entity* preview = new Entity(0, 0, "preview");
	placement = new PlacementManager(preview);
	addToWorld(placement);
	addToWorld(preview);

	Text_UI_element* game_over = new Text_UI_element(Global::SCREEN_WIDTH / 2 - 100, Global::SCREEN_HEIGHT / 2, font, "Game Over!");
	base = new Spaceport(scale * 5, scale * 15, *expl_ani, game_over);
	addToWorld(base);
	addToWorld(game_over);

	//register a key listener to place towers, bombs and workers
	decltype(keyClickListeners)::callbackType key_listener = OnKeyPress;
	keyDownListeners.add(key_listener);


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

		//update UI values
		string num = std::to_string(base->getResources());
		text->setText(num);

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