#include "FPSCounter.h"



namespace GameEngine
{
	FPSCounter::FPSCounter()
	{
	}


	FPSCounter::~FPSCounter()
	{
	}

	SDL_Surface * FPSCounter::getFrame(SDL_Renderer *)
	{
		//TODO: Make a 
		return nullptr;
	}

	void FPSCounter::Update()
	{
		Uint32 dTime = Global::deltaTime();
		Uint32 fps = 1000 / dTime;
		std::cout << "Fps: " << fps << " ,deltaTime: " << dTime << std::endl;
	}

	void FPSCounter::enableDrawing(TTF_Font * font)
	{
		renderSelf = true;
		this->font = font;
	}

	void FPSCounter::disableDrawing() {
		renderSelf = false;
		this->font = nullptr;
	}
}
