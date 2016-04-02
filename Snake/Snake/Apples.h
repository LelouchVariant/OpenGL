#pragma once

class Apples
{
public:
	Apples();
	Apples(int n, int m, int scale);
	~Apples();
	void newApple();
	void drawApple();

private:
	int x, y;
	int n, m, scale;
};

