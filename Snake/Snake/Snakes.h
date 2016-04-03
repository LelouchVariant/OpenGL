#pragma once
class Snakes
{
public:
	Snakes();
	Snakes(int SCALE, int N, int M);
	~Snakes();

	int getSpeedSnake();
	void setSnakeDirection(int position);
	void drawSnake();
	void snakeRun();
	void snakeEat();
	void checkGameOver();
	int getSnakeHeadX();
	int getSnakeHeadY();
	
private:
	int x, y;
	int m, n;
	int SnakeSpeed;
	int snakeNum, snakeDirection;
	int scale;

	struct SnakePos
	{
		int x;
		int y;
	} snakePosition[100];
};

