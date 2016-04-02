#pragma once

class Apples
{
public:
	Apples();
	Apples(int n, int m, int scale);
	~Apples();

	void newApple();
	void drawApple();

	int getX();
	int getY();

private:
	int x, y;
	int n, m, scale;
};

