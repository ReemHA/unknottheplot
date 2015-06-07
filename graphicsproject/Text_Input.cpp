#include "Text_Input.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>



TTF_Font* font;
SDL_Color textColor = { 255, 255, 255, 255 }; // white

SDL_Texture* blendedTexture;
SDL_Rect blendedRect;
SDL_Window* window;
SDL_Renderer* renderer;


bool Init(float posx, float posy)
{
	if (!SetupTTF("./res/font.ttf"))
		return false;

	CreateTextTextures(posx, posy);

	return true;
}

Text_Input::Text_Input(float posx, float posy)
{

	if (!Init(posx, posy)){
		std::cout << "error position";
	}

	Run();

	// Clean up font
	TTF_CloseFont(font);
}


Text_Input::~Text_Input()
{

}
void Render()
{
	// Clear the window and make it all red
	SDL_RenderClear(renderer);

	// Render our text objects ( like normal )
	SDL_RenderCopy(renderer, blendedTexture, nullptr, &blendedRect);
	// Render the changes above
	SDL_RenderPresent(renderer);
}

void Run()
{
	Render();
	std::cout << "Press any key to exit\n";
	std::cin.ignore();
}
// Initialization 
// ==================================================================
bool SetupTTF(const std::string &fontName)
{
	// SDL2_TTF needs to be initialized just like SDL2
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << TTF_GetError() << std::endl;
		return false;
	}

	// Load our fonts, with a huge size
	font = TTF_OpenFont(fontName.c_str(), 90);

	// Error check
	if (font == nullptr)
	{
		std::cout << " Failed to load font : " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}
void CreateTextTextures(float x, float y)
{

	SDL_Surface* blended = TTF_RenderText_Blended(font, "blended", textColor);
	blendedTexture = SurfaceToTexture(blended);

	SDL_QueryTexture(blendedTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = x;
	blendedRect.y = y;

}
// Convert an SDL_Surface to SDL_Texture. 
SDL_Texture* SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
