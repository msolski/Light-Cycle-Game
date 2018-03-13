#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "Char.hpp"

using namespace std;

GLsizei winWidth = 640, winHeight = 480;
const float DEGTORADCONVERT = 3.14159/180;
Char player(1);

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, winWidth, winHeight, 0.0);
	glFlush();
}

// The Draw Callback Function
void drawList() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Player
	player.drawTrail();
	player.drawChar();

	// Not player
	glFlush();
}

void idle() {
	player.moveChar();
	Sleep(20);
	glutPostRedisplay();
}

void moveChar(unsigned char key, int x, int y){
	switch(key){
	case 'w': player.changeDir(Char::up); break;
	case 's': player.changeDir(Char::down); break;
	case 'a': player.changeDir(Char::left); break;
	case 'd': player.changeDir(Char::right); break;
	case ' ': player.changeSpeed(); break;
	case 27: exit(0); break;
	}
}

// main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    setbuf(stdout, NULL);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Stuff");

    init();

    //Callback Functions
    glutDisplayFunc(drawList);
    glutIdleFunc(idle);
    //glutMouseFunc(mouseMove);
    glutKeyboardFunc(moveChar);

    glutMainLoop();
}
