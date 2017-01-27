#include "TextureManager.h"


namespace GameEngine {
	TextureManager::TextureManager()
	{
		SingleTexture* texture = new SingleTexture();
		texture->bounds = { 0, 0, 16, 16 };
		texture->raw_texture = NULL;
		default_texture = texture;
	}
	TextureManager::TextureManager(SDL_Renderer* renderer)
	{
		setupDefault(renderer);
		SingleTexture* texture = new SingleTexture();
		texture->bounds = { 0, 0, 16, 16 };
		texture->raw_texture = NULL;
		default_texture = texture;
	}

	TextureManager::~TextureManager()
	{
		std::cout << "deconstructing texturemanager..." << std::endl;

		decltype(raw_texture_list)::const_iterator iterator;
		for (iterator = raw_texture_list.begin(); iterator != raw_texture_list.end(); ++iterator) {
			SDL_Texture* texture = *iterator;
			SDL_DestroyTexture(texture);
		}
		raw_texture_list.clear();

		for(int i = 0; i < texture_array.size(); i++)
		{
			delete texture_array[i];
			texture_array[i] = nullptr;
		}

		SDL_FreeSurface(default_surface);
		SDL_DestroyTexture(default_texture->raw_texture);
		delete default_texture;
	}

	SingleTexture& TextureManager::get(int id)
	{
		if (id > index || id < 0) {
			return *default_texture;
		}

		return *texture_array[id];//TODO: Make sure the decontructor deletes all structs
	}

	SingleTexture& TextureManager::get(string name)
	{
		int id = getID(name);
		if (id != -1) {
			return get(id);
		}

		return *default_texture;
	}

	int TextureManager::add(SDL_Texture* texture, const string& name)
	{
		Rectangle bounds;
		bounds.x = 0;
		bounds.y = 0;
		int w, h;
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		bounds.width = w;
		bounds.height = h;

		return add(texture, name, bounds);
	}

	int TextureManager::add(SDL_Texture * texture, const string& texture_name, const Rectangle& bounds)
	{
		if (texture_name != "unnamed") {
			int texture_id = getID(texture_name);
			if (texture_id != -1) {
				std::cerr << "Texture name: '" << texture_name << "' is already defined with id: '" << texture_id << "'." << std::endl;
				return texture_id;
			}
		}

		auto raw_texture = get_raw_texture(texture);
		if (raw_texture == nullptr) {
			raw_texture = texture;
			raw_texture_list.push_back(raw_texture);
		}
		
		auto single_texture_id = get_SingleTexture_ID(texture, bounds);
		if (single_texture_id == -1) {
			SingleTexture* single_texture = new SingleTexture();
			single_texture->raw_texture = raw_texture;
			single_texture->bounds = bounds;

			//add singletexture to array
			if (index < maxTextures) {
				texture_array[index] = single_texture;
				//register id with string
				registerID(texture_name, index);

				return index++;
			}
			else {
				delete single_texture;
			}
		}

		return single_texture_id;
	}

	int TextureManager::add(SDL_Texture * texture, const Rectangle & bounds)
	{
		return add(texture, "unnamed", bounds);
	}

	int TextureManager::getID(string texture_name)
	{
		decltype(id_dictionairy)::iterator iterator = id_dictionairy.find(texture_name);
		if (iterator != id_dictionairy.end()) {
			int id = iterator->second;
			return id;
		}

		return -1;
	}

	void TextureManager::registerID(string key, int id)
	{
		if (id >= 0 && id <= index) {
			decltype(id_dictionairy)::iterator iterator = id_dictionairy.find(key);
			if (iterator == id_dictionairy.end()) {
				id_dictionairy.insert(std::pair<string, int>(key, id));
			}
		}
	}

	void TextureManager::setupDefault(SDL_Renderer * renderer)
	{
		Uint32 rMask, gMask, bMask, aMask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rMask = 0xff000000;
		gMask = 0x00ff0000;
		bMask = 0x0000ff00;
		aMask = 0x000000ff;
#else
		rMask = 0x000000ff;
		gMask = 0x0000ff00;
		bMask = 0x00ff0000;
		aMask = 0xff000000;
#endif

		default_surface = SDL_CreateRGBSurface(0, 16, 16, 32,
			rMask, gMask, bMask, aMask);

		SDL_Rect bg{ 0, 0, 16, 16 };
		SDL_FillRect(default_surface, &bg, SDL_MapRGBA(default_surface->format, 75, 0, 130, 255));

		SDL_Rect inner{ 1, 1, 14, 14 };
		SDL_FillRect(default_surface, &inner, SDL_MapRGBA(default_surface->format, 75, 0, 130, 200));

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, default_surface);
		default_texture = new SingleTexture();
		default_texture->raw_texture = texture;
		default_texture->bounds = { 0,0,16,16 };

		
	}

	void TextureManager::setupDefault(SingleTexture* newTexture, SDL_Surface * newSurface)//TODO: Make sure the old texture gets destoyed
	{
		
		SDL_FreeSurface(default_surface);
		delete default_texture;

		default_surface = newSurface;
		default_texture = newTexture;
	}

	SingleTexture& TextureManager::getDefault()
	{
		return *default_texture;
	}

	SDL_Surface * TextureManager::getDefaultSurface()
	{
		return default_surface;
	}

	SDL_Texture* TextureManager::get_raw_texture(SDL_Texture * texture)
	{
		for each (SDL_Texture* texture_raw in raw_texture_list)
		{
			if (texture_raw == texture) {
				return texture_raw;
			}
		}
		return nullptr;
	}
	SingleTexture* TextureManager::get_SingleTexture(SDL_Texture* texture_ptr, const Rectangle& bounds)
	{
		for each (SingleTexture* single_texture in texture_array)
		{
			if (single_texture->raw_texture == texture_ptr && single_texture->bounds == bounds) {
				return single_texture;
			}
		}
		return nullptr;
	}

	int TextureManager::get_SingleTexture_ID(SDL_Texture* texture_ptr, const Rectangle& bounds)
	{
		for (int i = 0; i < index; i++) {
			if (texture_array[i]->raw_texture == texture_ptr && texture_array[i]->bounds == bounds) {
				return i;
			}
		}
		return -1;
	}
}