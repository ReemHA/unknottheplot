#ifndef DISPLAY_INCLUDED_H
#define DISPLAY_INCLUDED_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Display
{
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();

	SDL_Renderer* renderer;
	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	void Clear(float r, float g, float b, float a);
	void SwapBuffers();
	void renderText(const std::string &message, SDL_Color color, int fontSize, int DISPLAY_WIDTH, int DISPLAY_HEIGHT);
	void renderTexture(SDL_Texture *tex, int x, int y, SDL_Rect *clip = nullptr);
	void renderTexture_2(SDL_Texture *tex, SDL_Rect dst, SDL_Rect *clip = nullptr);

protected:
private:
	void operator=(const Display& display) {}
	Display(const Display& display) {}
};

#endif