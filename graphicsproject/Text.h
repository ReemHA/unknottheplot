#include "glm/glm/glm.hpp"
#include "GL\glut.h"
#pragma once
class Text
{

public:
	Text(const glm::vec3& pos, const glm::vec3& RGB, char* string){
		this->pos = pos;
		this->RGB = RGB;
		this->string = string;
	}
	void setPos(const glm::vec3& pos){
		this->pos = pos;
	}
	void setColor(const glm::vec3& RGB){
		this->RGB = RGB;
	}
	void setString(char* string){
		this->string = string;
	}

	glm::vec3* getPosX() { 
		return &pos; 
	}
	glm::vec3* getColor() { 
		return &RGB; 
	}
	char* GetString() { 
		return string; 
	}

	void outputText(Text text){
		glColor3f(text.RGB.r, text.RGB.g, text.RGB.b);
		glRasterPos3f(text.pos.x, text.pos.y, text.pos.z);
		int len, i;
		len = (int)strlen(string);
		for (i = 0; i < len; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
		}
	}
private:
	glm::vec3 pos;
	glm::vec3 RGB;
	char* string;

};

