#include "Texture.h"

Texture::Texture() {
	fileLocation = "";
	texture = NULL;
	renderer = NULL;
}

Texture::Texture(std::string fileLocation)
{
	this->fileLocation = fileLocation;
	texture = NULL;
	renderer = NULL;
}

Texture::~Texture()
{
	if (texture != NULL)
		SDL_DestroyTexture(texture);
	
}

void Texture::SetFileLocation(std::string fileLocation)
{
	this->fileLocation = fileLocation;
}

std::string Texture::GetFileLocation()
{
	return fileLocation;
}

void Texture::SetRenderer(SDL_Renderer * renderer)
{
	this->renderer = renderer;
}

SDL_Renderer * Texture::GetRenderer()
{
	return renderer;
}

bool Texture::Open()
{
	//if (fileLocation.empty() || texture == NULL)
		//return false;

	SDL_Surface* surface = IMG_Load(fileLocation.c_str());
	if(surface == NULL)
		return false;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	return texture;
}

bool Texture::Open(std::string fileLocation)
{
	SetFileLocation(fileLocation);

	return Open();
}

bool Texture::Open(SDL_Renderer * renderer)
{
	SetRenderer(renderer);

	return Open();
}

bool Texture::Open(std::string fileLocation, SDL_Renderer * renderer)
{
	SetFileLocation(fileLocation);
	SetRenderer(renderer);

	return Open();
}
