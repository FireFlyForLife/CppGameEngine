#include "Text_UI_element.h"



namespace GameEngine
{
	Text_UI_element::Text_UI_element(int x, int y, TTF_Font* font, string text, string prefix) : UI_element(x, y), text(text), prefix(prefix), font(font)
	{
		renderSelf = true;
	}

	Text_UI_element::~Text_UI_element()
	{
		cleanupLastFrame();
	}

	std::pair<SingleTexture*, Rectangle*> Text_UI_element::getFrame(SDL_Renderer * renderer)
	{
		//TODO: Add color
		SDL_Color color = { 0, 0, 0 };
		string render_text = prefix + text;
		SDL_Surface* surfaceTxt = TTF_RenderText_Solid(font, render_text.c_str(), color);
		SDL_Texture* txt = SDL_CreateTextureFromSurface(renderer, surfaceTxt);
		//Uhm why is this turned around?
		Rectangle target{ 0, 0, surfaceTxt->h, surfaceTxt->w };

		SDL_FreeSurface(surfaceTxt);

		SingleTexture* texture = new SingleTexture();
		texture->raw_texture = txt;
		texture->bounds = target;

		cleanupLastFrame();
		last_frame = new std::pair<SingleTexture*, Rectangle*>(texture, &target);

		return *last_frame;
	}


	void Text_UI_element::setPrefix(string newString)
	{
		prefix = newString;
	}
	string Text_UI_element::getPrefix()
	{
		return prefix;
	}
	void Text_UI_element::setText(string newString)
	{
		text = newString;
	}
	string Text_UI_element::getText()
	{
		return text;
	}
	TTF_Font * Text_UI_element::getFont()
	{
		return font;
	}
	void Text_UI_element::cleanupLastFrame()
	{
		if (last_frame != nullptr) {
			delete last_frame->second;
			delete last_frame->first;
			delete last_frame;
			last_frame = nullptr;
		}
	}
}
