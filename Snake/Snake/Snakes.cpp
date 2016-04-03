#include "stdafx.h"
#include "Snakes.h"
#include <Windows.h>

Snakes::Snakes()
{
}

Snakes::Snakes(int SCALE,int N,int M)
{
	SnakeSpeed = 150;
	snakePosition[0].x = 10;  snakePosition[0].y = 10; //snake start coordinat
	snakeDirection = 1;
	snakeNum = 1;
	scale = SCALE;
	n = N;
	m = M;
}

Snakes::~Snakes()
{
}

void  Snakes::drawSnake() {
	glColor3f(0.647, 0.164, 0.164);
	for (int i = 0; i < snakeNum; i++) {
		glRectf(snakePosition[i].x*scale, snakePosition[i].y*scale, (snakePosition[i].x + 1)*scale, (snakePosition[i].y + 1)*scale);
	}
}

int Snakes::getSpeedSnake() {
	return SnakeSpeed;
}

void Snakes::setSnakeDirection(int position) {
	snakeDirection = position;
}

void Snakes::snakeRun() {
	for (int i = snakeNum; i > 0; --i) {
		snakePosition[i].x = snakePosition[i-1].x;
		snakePosition[i].y = snakePosition[i-1].y;
	}

	switch (snakeDirection)
	{
	case 0: snakePosition[0].y += 1;
		break;
	case 1: snakePosition[0].x -= 1;
		break;
	case 2: snakePosition[0].x += 1;
		break;
	case 3: snakePosition[0].y -= 1;
		break;
	}
}

void Snakes::snakeEat() {
	snakeNum++;
	SnakeSpeed -= 3;
}

int Snakes::getSnakeHeadX() {
	return snakePosition[0].x;
}

int Snakes::getSnakeHeadY() {
	return snakePosition[0].y;
}

void Snakes::checkGameOver() {
	if (snakePosition[0].x > n || snakePosition[0].x < 0 || snakePosition[0].y > m || snakePosition[0].y < 0) {
		MessageBox(NULL, L"Game over", L"Game over!!!", MB_OK);
		exit(0);
	}

	
		for (int i(1); i < snakeNum;i++)
			if (snakePosition[0].x == snakePosition[i].x && snakePosition[0].y == snakePosition[i].y) {
				MessageBox(NULL, L"Game over", L"Game over!!!", MB_OK);
				exit(0);
			}
}