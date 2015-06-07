#pragma once
class Text_Input
{
public:
	Text_Input(float posx, float posy);
	
	// Our new function for setting uo SDL_TTF
	bool SetupTTF(const std::string &fontName);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
	void CreateTextTextures();
		
	~Text_Input();
private:
	float posX;
	float posY;
};

