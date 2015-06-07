#include "display.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/glew.h>
#include <iostream>
#include "mesh.h"
Display::Display(int width, int height, const std::string& title)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	Display::m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	m_glContext = SDL_GL_CreateContext(Display::m_window);

	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		std::cerr << "Glew failed to initialize!" << std::endl;
	}

	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);
}

Display::~Display()
{
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Display::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::SwapBuffers()
{
	SDL_GL_SwapWindow(m_window);
}

//function renderText
void Display::renderTexture_2(SDL_Texture *tex, SDL_Rect dst, SDL_Rect *clip){
	SDL_RenderCopy(Display::renderer, tex, clip, &dst);
	SDL_RenderPresent(Display::renderer);
	SDL_Delay(100);
}
void Display::renderTexture(SDL_Texture *tex, int x, int y, SDL_Rect *clip){
	SDL_Rect dst;
	dst.x = x;
	dst.y = y;
	if (clip != nullptr){
		dst.w = clip->w;
		dst.h = clip->h;
	}
	else {
		SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
	}
	renderTexture_2(tex, dst, clip);
}

void Display::renderText(const std::string &message, SDL_Color color, int fontSize, int DISPLAY_WIDTH, int DISPLAY_HEIGHT)
{
	const std::string &fontFile = "res/font.ttf";
	
	TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
	if (font == nullptr){
		std::cout << "TTF_OpenFont";
	}

	/*Create some variables.*/
	SDL_Surface *Message = TTF_RenderText_Blended(const_cast<TTF_Font*>(font), message.c_str(), color);
	unsigned Texture = 0;

	/*Generate an OpenGL 2D texture from the SDL_Surface*.*/
	glGenTextures(1, &Texture);
	glBindTexture(GL_TEXTURE_2D, Texture);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, Message->w, Message->h, 0, GL_BGRA,
		GL_UNSIGNED_BYTE, Message->pixels);

	int x = DISPLAY_WIDTH / 4 - 50;
	int y = DISPLAY_HEIGHT / 4 - 50;

	/*Draw this texture on a quad with the given xyz coordinates.*/
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0); glVertex3d(x, y, 30.0f);
	glTexCoord2d(1, 0); glVertex3d(x + Message->w, y, 30.0f);
	glTexCoord2d(1, 1); glVertex3d(x + Message->w, y + Message->h, 30.0f);
	glTexCoord2d(0, 1); glVertex3d(x, y + Message->h, 30.0f);
	glEnd();

	/*Clean up.*/
	glDeleteTextures(1, &Texture);
	SDL_FreeSurface(Message);

	
}