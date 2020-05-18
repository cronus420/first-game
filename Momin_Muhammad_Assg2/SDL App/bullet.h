#pragma once
class bullets
{
public:
	bullets(void);
	~bullets(void);

	int bullet1;
	float xpos;
	float ypos;
	bool alive;
	void draw();
	void update();
	
};

