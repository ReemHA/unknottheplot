#include <iostream>
#include <SDL2/SDL.h>
#include "display.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"
#include "GL\glut.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "cleanup.h"
static const int DISPLAY_WIDTH = 1900;
static const int DISPLAY_HEIGHT = 1200;
int index = 0;
int trials = 5;
float counter = 0.0f;
float sinCounter = 1.1f;
float counter2 = 0.0f;
bool KEYS[26];


/*void handle_mouseEvents(SDL_Event* event, Transform transform){
	//If the left mouse button was pressed
	if (event->type == SDL_MOUSEBUTTONDOWN)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//If the mouse is over the button
		//if ((x > transform.GetPos()->x) && (x < transform.GetPos()->x + w) && (y > transform.GetPos()->y) && (y < transform.GetPos()->y + box.h))
		{
			//Set the button sprite
		}
	}
}
*/
void check_win(){
	if (index == 3){
	//	exit(0);
	}
	else {
		index++;
	}
}

void check_lose(){
	if (trials == 0){
	//	exit(0);
	}
	else {
		trials--;
	}
}
void move_floatingBallL(Transform t){
	t.GetPos()->x = sinCounter * counter2;
	check_win();
}

void move_floatingBallD(Transform t){
	t.GetPos()->y = sinCounter * counter;
	check_lose();
}


int main(int argc, char** argv)
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");	
	Mesh sea("./res/islandt.obj");
	Shader shader("./res/basicShader");
	Texture sea_texture("./res/water.jpg");
	
	Transform transform;
	Transform transform2;

	Mesh mountain("./res/mountaint.obj");
	Texture mountain_texture("./res/material1.jpg");
	 
	Mesh floatingball("./res/ball.obj");
	Texture  floatingball_texture("./res/bricks.jpg");

	Mesh board("./res/board.obj");
	Texture  board_texture("./res/M_2166tanCAM1.png");

	Mesh trunk("./res/trunk.obj");
	Texture trunk_texture("./res/Color_002.jpg");

	Mesh leaves("./res/leaves.obj");
	Texture  leaves_texture("./res/_Color_004_1.jpg");

	Mesh character("./res/model.obj");
	Texture  character_text("./res/model.jpg");

	Camera camera(glm::vec3(50.0f, 8.0f, -60.0f), 40.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 1.0f, 800.0f);
	camera.RotateY(-50.0);

	SDL_Event e;
	bool isRunning = true;
	for (int i = 0; i < 26; i++) { // init them all to false
		KEYS[i] = false;
	}

	while (isRunning)
	{

		display.Clear(255.0f, 255.0f, 255.0f, 0.0f);
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT){
				isRunning = false;

			}
			if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE){
				isRunning = false;
			}

			else{
				if (KEYS[SDLK_s]){
					transform2.GetPos()->x = sinCounter * counter2;
					check_win();
				}
				if (KEYS[SDLK_a]){
					transform2.GetPos()->x = sinCounter * counter2;
					check_win();
				}
				if (KEYS[SDLK_l]){
					transform2.GetPos()->x = sinCounter * counter2;
					check_win();
				}
				if (KEYS[SDLK_t]){
					transform2.GetPos()->x = sinCounter * counter2;
					check_win();
				}
				else {
					transform2.GetPos()->y = sinCounter * counter;
					check_lose();;
				}
			}
		}
		

		//float sinCounter = sinf(counter);
		//float absSinCounter = abs(sinCounter);
		//transform2.GetRot()->y = counter * 100;
		//transform.GetRot()->z = counter * 100;
		//transform.GetScale()->x = absSinCounter;
		//transform.GetScale()->y = absSinCounter;
		SDL_Color color = { 0.0f, 0.0f, 0.0f, 255.0f };
		glm::vec3 rot(0.0, 20.0, 0.0);
		transform.SetRot(rot);
		std::cout << transform.GetPos()->y;
		shader.Bind();
		sea_texture.Bind();
		shader.Update(transform, camera);
		sea.Draw();
		mountain_texture.Bind();
		mountain.Draw();
		board_texture.Bind();
		board.Draw();

		leaves_texture.Bind();
		leaves.Draw();
		trunk_texture.Bind();
		trunk.Draw();
		floatingball_texture.Bind();
		//transform2.GetPos()->y = sinCounter * counter;
		transform.GetPos()->x = 15.0f;
		shader.Update(transform2, camera);
		floatingball.Draw();
		character_text.Bind();
		character.Draw();
		display.SwapBuffers();
		SDL_Delay(10);
		counter -= 0.005f;
		counter2 += 0.005f;

	}

	return 0;

}