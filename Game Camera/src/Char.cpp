#include "Char.hpp"
#include <string>
#include <iostream>

using namespace std;

Char::Char(int charId) {
	id = charId;
	colour[0] = 0.2;
	colour[1] = 0.8;
	colour[2] = 1.0;

	speed = slowSpeed;
	dir = up;
	pos.x = 275; pos.y = 300;

	trailList[0].x = pos.x; trailList[0].y = pos.y;
	numOfTrail = 1;
}

void Char::drawChar() {
	glColor3f(colour[0], colour[1], colour[2]);
	glRectf(pos.x-5, pos.y+5, pos.x+5, pos.y-5);
}

void Char::changeDir(direction key){
	// If it's not the same direction
	if(dir != key){
		// And it's not the opposite direction
		if(((dir==up)&(key!=down)) || ((dir==down)&(key!=up)) || ((dir==left)&(key!=right)) || ((dir==right)&(key!=left))){
			dir = key;

			trailList[numOfTrail].x = pos.x; trailList[numOfTrail].y = pos.y;
			cout << numOfTrail;
			cout << ": ";
			cout << trailList[numOfTrail].x;
			cout << ", ";
			cout << trailList[numOfTrail].y;
			cout << "\n";
			numOfTrail++;
		}
	}
}

void Char::moveChar(){
	/*if (charDie()){
		printf("dead\n");
	}*/

	switch(dir){
	case up: pos.y -= speed; break;
	case down: pos.y += speed; break;
	case left: pos.x -= speed; break;
	case right: pos.x += speed; break;
	}
}

void Char::changeSpeed() {
	if(speed == slowSpeed) speed = fastSpeed;
	else speed = slowSpeed;
}

// Trail is made out of a line between points
// A point is drawn at the very beginning and after each turn
// The cycle itself is the last "point" in the line loop
// TODO: Fill in corners
void Char::drawTrail(){
	bool death = false;
	glLineWidth(5.0);
	glColor3f(colour[0], colour[1], colour[2]);

	glBegin(GL_LINE_STRIP);

		for(int i=0; i<numOfTrail; i++){
			glVertex2f(trailList[i].x, trailList[i].y);

			// If the player is in between two points, he dies
			if(i>0){
				// If the line is vertical
				if(trailList[i].x == trailList[i-1].x){

				}
				// If the line is horizontal
				else if(trailList[i].y == trailList[i-1].y){

				}

			}

		}
		glVertex2f(pos.x, pos.y);

	glEnd();

}

bool Char::charDie(){
	// Look ahead a bit
	struct PlayerPosition ahead;
	ahead.x = pos.x;
	ahead.y = pos.y;

	switch(dir){
	case up: ahead.y -= 10; break;
	case down: ahead.y += 10; break;
	case left: ahead.x -= 10; break;
	case right: ahead.x += 10; break;
	}

	unsigned char pixel[3];
	glReadPixels(ahead.x , ahead.y , 1 , 1 , GL_RGB , GL_UNSIGNED_BYTE, pixel);

	if(pixel[0] != 0){
		return true;
	}

	return false;
}
