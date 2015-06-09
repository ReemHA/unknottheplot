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
	if (counter2 == 2){
		SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
		std::cout << "CONGRATULAIONS YOU WON";
	}
}

void check_lose(){
	if (counter == -2){
		SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
		std::cout << "I AM SO SORRY. YOU LOST.";
	}

}

int main(int argc, char** argv)
{
	Display display(DISPLAY_WIDTH, DISPLAY_HEIGHT, "OpenGL");	
	Mesh sea("./res/islandt.obj");
	Shader shader("./res/basicShader");
	Texture sea_texture("./res/water.jpg");
	
	Transform transform;
	Transform transform2;
	Transform transform3;
	Transform alphapet;
	Texture white("./res/Letters/Material.jpg");
	Mesh mountain("./res/mountaint.obj");
	Texture mountain_texture("./res/material1.jpg");
	 
	Mesh floatingball("./res/ball1.obj");
	Texture  floatingball_texture("./res/bricks.jpg");

	Mesh board("./res/board.obj");
	Texture  board_texture("./res/M_2166tanCAM1.png");

	Mesh trunk("./res/trunk.obj");
	Texture trunk_texture("./res/Color_002.jpg");

	Mesh leaves("./res/leaves.obj");
	Texture  leaves_texture("./res/_Color_004_1.jpg");

	Mesh character("./res/model.obj");
	Texture  character_text("./res/model.jpg");


	Mesh letters("./res/Letters/All.obj");
	Texture letters_texture("./res/Letters/All/Material.jpg");

	Mesh A("./res/Letters/A.obj"); Texture A_t("./res/Letters/A/a.png", 1);
	Mesh B("./res/Letters/B.obj"); Texture B_t("./res/Letters/B/b.png", 1);
	Mesh C("./res/Letters/C.obj"); Texture C_t("./res/Letters/C/c.png", 1);
	Mesh D("./res/Letters/D.obj"); Texture D_t("./res/Letters/D/d.png", 1);
	Mesh E("./res/Letters/E.obj"); Texture E_t("./res/Letters/E/e.png", 1);
	Mesh F("./res/Letters/F.obj"); Texture F_t("./res/Letters/F/f.png", 1);
	Mesh G("./res/Letters/G.obj"); Texture G_t("./res/Letters/G/g.png", 1);
	Mesh H("./res/Letters/H.obj"); Texture H_t("./res/Letters/H/h.png", 1);
	Mesh I("./res/Letters/I.obj"); Texture I_t("./res/Letters/I/i.png", 1);
	Mesh J("./res/Letters/J.obj"); Texture J_t("./res/Letters/J/j.png", 1);
	Mesh K("./res/Letters/K.obj"); Texture K_t("./res/Letters/K/k.png", 1);
	Mesh L("./res/Letters/L.obj"); Texture L_t("./res/Letters/L/l.png", 1);
	Mesh M("./res/Letters/M.obj"); Texture M_t("./res/Letters/M/m.png", 1);
	Mesh N("./res/Letters/N.obj"); Texture N_t("./res/Letters/N/n.png", 1);
	Mesh O("./res/Letters/O.obj"); Texture O_t("./res/Letters/O/o.png", 1);
	Mesh P("./res/Letters/P.obj"); Texture P_t("./res/Letters/P/p.png", 1);
	Mesh Q("./res/Letters/Q.obj"); Texture Q_t("./res/Letters/Q/q.png", 1);
	Mesh R("./res/Letters/R.obj"); Texture R_t("./res/Letters/R/r.png", 1);
	Mesh S("./res/Letters/S.obj"); Texture S_t("./res/Letters/S/s.png", 1);
	Mesh T("./res/Letters/T.obj"); Texture T_t("./res/Letters/T/t.png", 1);
	Mesh U("./res/Letters/U.obj"); Texture U_t("./res/Letters/U/u.png", 1);
	Mesh V("./res/Letters/V.obj"); Texture V_t("./res/Letters/V/v.png", 1);
	Mesh W("./res/Letters/W.obj"); Texture W_t("./res/Letters/W/w.png", 1);
	Mesh X("./res/Letters/X.obj"); Texture X_t("./res/Letters/X/x.png", 1);
	Mesh Y("./res/Letters/Y.obj"); Texture Y_t("./res/Letters/Y/y.png", 1);
	Mesh Z("./res/Letters/Z.obj"); Texture Z_t("./res/Letters/Z/z.png", 1);
	Mesh All("./res/Letters/All.obj");
	Texture wooden_letters("./res/LettersBoard2.png");

	Camera camera(glm::vec3(50.0f, 8.0f, -60.0f), 40.0f, (float)DISPLAY_WIDTH / (float)DISPLAY_HEIGHT, 1.0f, 800.0f);
	camera.RotateY(-50.0);

	SDL_Event e;
	bool isRunning = true;
	for (int i = 0; i < 26; i++) { // init them all to false
		KEYS[i] = false;
	}
	transform3.SetRot(glm::vec3(0.0f, 0.0f, 0.0f));
	transform3.SetPos(glm::vec3(3.0f, 0.5f, 3.5f));

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

			else if (e.type == SDL_KEYDOWN){
				switch (e.key.keysym.sym){
				case SDLK_s:
					transform2.SetPos(glm::vec3(transform2.GetPos()->x + sinCounter * counter2, transform2.GetPos()->y, transform2.GetPos()->z));
					transform3.SetPos(glm::vec3(transform3.GetPos()->x + sinCounter * counter2, transform3.GetPos()->y, transform3.GetPos()->z));
					counter2 += 0.4f;

					check_win();
					break;
				
				case SDLK_a:
					transform2.SetPos(glm::vec3(transform2.GetPos()->x + sinCounter * counter2, transform2.GetPos()->y, transform2.GetPos()->z));
					transform3.SetPos(glm::vec3(transform3.GetPos()->x + sinCounter * counter2, transform3.GetPos()->y, transform3.GetPos()->z));
					counter2 += 0.4f;
					check_win();
					break;
				case SDLK_l: 
					transform2.SetPos(glm::vec3(transform2.GetPos()->x + sinCounter * counter2, transform2.GetPos()->y, transform2.GetPos()->z));
					transform3.SetPos(glm::vec3(transform3.GetPos()->x + sinCounter * counter2, transform3.GetPos()->y, transform3.GetPos()->z));
					counter2 += 0.4f;
					check_win();
					break;
				case SDLK_t:
					transform2.SetPos(glm::vec3(transform2.GetPos()->x + sinCounter * counter2, transform2.GetPos()->y, transform2.GetPos()->z));
					transform3.SetPos(glm::vec3(transform3.GetPos()->x + sinCounter * counter2, transform3.GetPos()->y, transform3.GetPos()->z));
					counter2 += 0.4f;
					check_win();
					break;
				default:
					transform2.SetPos(glm::vec3(transform2.GetPos()->x, transform2.GetPos()->y + sinCounter * counter, transform2.GetPos()->z));
					transform3.SetPos(glm::vec3(transform3.GetPos()->x, transform2.GetPos()->y + sinCounter * counter, transform3.GetPos()->z));
					counter -= 0.5f;
					check_lose();;
					break;
				}
			}
		}
		

		//float sinCounter = sinf(counter);
		//float absSinCounter = abs(sinCounter);
		//transform2.GetRot()->y = counter * 100;
		//transform.GetRot()->z = counter * 100;
		//transform.GetScale()->x = absSinCounter;
		//transform.GetScale()->y = absSinCounter;

		
		//E.Draw(); F.Draw(); G.Draw(); H.Draw(); I.Draw(); K.Draw();
		//All.Draw();

		//letters_texture.Bind();
		//All.Draw();
		SDL_Color color = { 0.0f, 0.0f, 0.0f, 255.0f };
		glm::vec3 rot(0.0, 20.0, 0.0);
		transform.SetRot(rot);
		shader.Bind();
		sea_texture.Bind();
		shader.Update(transform, camera);
		sea.Draw();
		mountain_texture.Bind();
		mountain.Draw();

		A_t.Bind();  A.Draw();
		B_t.Bind();  B.Draw();
		C_t.Bind();  C.Draw();
		D_t.Bind();  D.Draw();
		E_t.Bind();  E.Draw();
		F_t.Bind();  F.Draw();
		G_t.Bind();  G.Draw();
		H_t.Bind();  H.Draw();
		I_t.Bind();  I.Draw();
		J_t.Bind();  J.Draw();
		K_t.Bind();  K.Draw();
		L_t.Bind();  L.Draw();
		M_t.Bind();  M.Draw();
		N_t.Bind();  N.Draw();
		O_t.Bind();  O.Draw();
		P_t.Bind();  P.Draw();
		Q_t.Bind();  Q.Draw();
		R_t.Bind();  R.Draw();
		S_t.Bind();  S.Draw();
		T_t.Bind();  T.Draw();
		U_t.Bind();  U.Draw();
		V_t.Bind();  V.Draw();
		W_t.Bind();  W.Draw();
		X_t.Bind();  X.Draw();
		Y_t.Bind();  Y.Draw();
		Z_t.Bind();  Z.Draw();

		leaves_texture.Bind();
		leaves.Draw();
		trunk_texture.Bind();
		trunk.Draw();
		
		transform.SetPos(glm::vec3(15.0f, 0.0f, 0.0f));
		shader.Update(transform2, camera);
		floatingball_texture.Bind();
		floatingball.Draw();
		character_text.Bind();
		shader.Update(transform3, camera);
		character.Draw();


		//transform2.GetPos()->y = sinCounter * counter;
		
		
		display.SwapBuffers();
		SDL_Delay(10);

	}
	std::cout << counter2 << std::endl;

	return 0;

}