// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Apples.h"


const int n(20), m(20); // nxm field
const int scale(25);    // size a box

int fieldWidth = scale*n;
int fieldHeight = scale*m;

int snakeNum = 4, snakeDirection;

Apples *apples[9];

struct
{
	int x;
	int y;
} s[100];


void tick()
{
	for (int i = snakeNum; i > 0; --i)
	{
		s[i].x = s[i - 1].x;
		s[i].y = s[i - 1].y;
	}


	if (snakeDirection == 0) s[0].y += 1;
	if (snakeDirection == 1) s[0].x -= 1;
	if (snakeDirection == 2) s[0].x += 1;
	if (snakeDirection == 3) s[0].y -= 1;

	//for (int i(0); i < 30; i++) {
	//	if ((s[0].x == appls[i].x) && (s[0].y == appls[i].y)) {
	//		snakeNum++; appls[i].newApple();
	//	}
	//}


	//if (s[0].x > n) snakeDirection = 1;
	//if (s[0].x < n) snakeDirection = 2;

	//if (s[0].y > m) snakeDirection = 3;
	//if (s[0].y < m) snakeDirection = 0;

}

void drawSnake() {
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < snakeNum; i++) {
		glRectf(s[i].x*scale, s[i].y*scale, (s[i].x + 1)*scale, (s[i].y + 1)*scale);
	}
}


void myKeyboard(int key, int a, int b) {
	switch (key)
	{
	case 101: snakeDirection = 0;
		break;

	case 102: snakeDirection = 2;
		break;

	case 100: snakeDirection = 1;
		break;

	case 103: snakeDirection = 3;
		break;
	}
}

void drawField()
{
	glColor3f(1.0, 0.549, 0.0);
	glBegin(GL_LINES);
	for (int i(0); i < fieldWidth; i += scale)
	{
		glVertex2f(i, 0); glVertex2f(i, fieldHeight);
	}
	for (int j(0); j < fieldHeight; j += scale)
	{
		glVertex2f(0, j); glVertex2f(fieldWidth, j);
	}
	glEnd();
}


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i(0); i < 9; i++)
		apples[i]->drawApple();
	drawField();
	drawSnake();
	glFlush();
}


void timer(int = 0)
{
	display();
	tick();
	glutTimerFunc(100, timer, 0);
}


int main(int argc, char **argv)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);


	for (int i(0); i < 9; i++)
		apples[i] = new Apples(n, m, scale);
	s[0].x = 10;  s[0].y = 10;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(fieldWidth, fieldHeight);
	glutInitWindowPosition((rect.right - fieldWidth) / 2.0, (rect.bottom - fieldHeight) / 2.0);
	glutCreateWindow("OpenGL snake");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, fieldWidth, 0, fieldHeight);
	glutDisplayFunc(display);     // Draw func
	glutTimerFunc(100, timer, 0); //Timer
	glutSpecialFunc(myKeyboard);  //Key
	glutMainLoop();

	delete[] apples;

	return 0;
}

