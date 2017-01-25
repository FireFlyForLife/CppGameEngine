#pragma once
#include "UI_element.h"
#include <SDL_ttf.h>

namespace GameEngine
{
	class Text_UI_element : public UI_element
	{
	public:
		Text_UI_element(int x, int y, TTF_Font* font, string text = "", string prefix = "");
		virtual ~Text_UI_element();

		virtual SDL_Surface* getFrame(SDL_Renderer* renderer) override;

		void setPrefix(string newString);
		string getPrefix();
		void setText(string newString);
		string getText();

		TTF_Font* getFont();

	protected:
		string prefix;
		string text;

		void cleanupLastFrame();

	private:
		TTF_Font* font;
		std::pair<SingleTexture*, Rectangle*>* last_frame = nullptr;
	};

}
