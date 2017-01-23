#pragma once
#include <string>
#include <SDL_render.h>
#include <SDL_image.h>

class Texture {
private:
	std::string fileLocation;
	SDL_Texture* texture;
	SDL_Renderer* renderer;

public:
	Texture();
	Texture(std::string fileLocation);
	~Texture();

	void SetFileLocation(std::string fileLocation);
	std::string GetFileLocation();
	void SetRenderer(SDL_Renderer* renderer);
	SDL_Renderer* GetRenderer();

	bool Open();
	bool Open(std::string fileLocation);
	bool Open(SDL_Renderer* renderer);
	bool Open(std::string fileLocation, SDL_Renderer* renderer);
};