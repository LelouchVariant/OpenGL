#pragma once
class Snakes
{
public:
	Snakes();
	Snakes(int SCALE);
	~Snakes();

	int getSpeedSnake();
	void setSnakeDirection(int position);
	void drawSnake();
	void snakeRun();
	void snakeEat();
	int getSnakeHeadX();
	int getSnakeHeadY();

private:
	int x, y;
	int SnakeSpeed;
	int snakeNum, snakeDirection;
	int scale;

	struct SnakePos
	{
		int x;
		int y;
	} snakePosition[100];
};

