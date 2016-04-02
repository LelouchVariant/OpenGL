// Snake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//classes
#include "Apples.h"
#include "Snakes.h"

const int n(20), m(20); // nxm field
const int scale(25);    // size a box

int fieldWidth = scale*n;
int fieldHeight = scale*m;




Apples *apples[20];
Snakes *snake = new Snakes(scale);


void tick()
{

	snake->snakeRun();

	for (int i(0); i < 20; i++) {
		if ((snake->getSnakeHeadX() == apples[i]->getX()) && (snake->getSnakeHeadY() == apples[i]->getY())) {
			apples[i]->newApple();
			snake->snakeEat();
		}
	}

	

	//if (s[0].x > n) snakeDirection = 1;
	//if (s[0].x < n) snakeDirection = 2;

	//if (s[0].y > m) snakeDirection = 3;
	//if (s[0].y < m) snakeDirection = 0;

}

void myKeyboard(int key, int a, int b) {
	switch (key)
	{
	case 101: snake->setSnakeDirection(0);
		break;

	case 102: snake->setSnakeDirection(2);
		break;

	case 100: snake->setSnakeDirection(1);
		break;

	case 103: snake->setSnakeDirection(3);
		break;
	}
}

void drawField() {
	glColor3f(0.180, 0.545, 0.341);
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

void display() {
	glClearColor(0.180, 0.545, 0.341,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i(0); i < 20; i++)
		apples[i]->drawApple();
	drawField();
	snake->drawSnake();
	glFlush();
}

void timer(int = 0) {
	display();
	tick();
	glutTimerFunc(snake->getSpeedSnake(), timer, 0);
}

int main(int argc, char **argv)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);


	for (int i(0); i < 20; i++)
		apples[i] = new Apples(n, m, scale);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(fieldWidth, fieldHeight);
	glutInitWindowPosition((rect.right - fieldWidth) / 2.0, (rect.bottom - fieldHeight) / 2.0);
	glutCreateWindow("OpenGL snake");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, fieldWidth, 0, fieldHeight);
	glutDisplayFunc(display);     // Draw func
	glutTimerFunc(snake->getSpeedSnake(), timer, 0); //Timer
	glutSpecialFunc(myKeyboard);  //Key
	glutMainLoop();

	delete[] apples;
	delete snake;

	return 0;
}