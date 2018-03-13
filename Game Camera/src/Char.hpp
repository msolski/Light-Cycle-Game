/*
 * Char.hpp
 *
 *  Created on: Feb 20, 2018
 *      Author: micha
 */

#ifndef CHAR_HPP_
#define CHAR_HPP_

#include <GL/glut.h>
#include <stdlib.h>
#include <list>
#include <stdio.h>

class Char {
public:
	static const int slowSpeed = 3;
	static const int fastSpeed = 6;
	enum direction {up, right, down, left};
	struct PlayerPosition {
	public:
		GLfloat x, y; // Position
	};

	GLfloat colour[3];
	GLfloat speed;
	direction dir;
	struct PlayerPosition pos;
	int id;

	struct PlayerPosition trailList[200];
	int numOfTrail;

	Char(int);
	bool charDie();
	void changeSpeed();
	void changeDir(direction);
	void drawChar();
	void moveChar();
	void drawTrail();
};

#endif /* CHAR_HPP_ */
