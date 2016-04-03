#include "stdafx.h"

const int widthField = 640;
const int widthHeight = 480;

int x, y;
int dx, dy;

void tick()
{
	x += dx;
	y += dy;

	if (x < 0) dx = -dx;
}

void myKeyboard(int key, int a, int b) {
	//switch (key)
	//{


	//}
}

void drawField() {
	glColor3f(1.0, 0.0, 1.0);
}

void drawBox() {
	glColor3f(1.0, 1.0, 0.0);
	glRectf(x, y, x + 40, y + 40);
}

void display() {
	glClearColor(0.180, 0.545, 0.341, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	drawField();
	drawBox();
	
	glFlush();
}

void timer(int = 0) {
	display();
	tick();
	glutTimerFunc(60, timer, 0);
}

int main(int argc, char **argv)
{
	RECT rect;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &rect, 0);

	x = y = 300;

	dx = -6;
	dy = 3;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(widthField, widthHeight);
	glutInitWindowPosition((rect.right - widthField) / 2.0, (rect.bottom - widthHeight) / 2.0);
	glutCreateWindow("OpenGL Vball");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, widthField, 0, widthHeight);
	glutDisplayFunc(display);     // Draw func
	glutTimerFunc(60, timer, 0); //Timer
	glutSpecialFunc(myKeyboard);  //Key
	glutMainLoop();



	return 0;
}
