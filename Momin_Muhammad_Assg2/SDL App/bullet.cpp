#include "bullet.h"
#include "GL_Functions.h"

bullets::bullets(void)
{
	bullet1 = LoadTexture("./images/Bullet1.png");
}


bullets::~bullets(void)
{
	FreeTexture(bullet1);
}



bullets arrayofbullets[10];

 void setupbullets()
{
	//Fire
	for(int i = 0;i < 10;i++)
	{
		if(arrayofbullets[i].alive == false)
		{
			arrayofbullets[i].xpos = GetMouseX();
			arrayofbullets[i].ypos = GetMouseY();
			arrayofbullets[i].alive = true;
			break;
		}

	}

	//Update/Draw
	for(int i = 0;i < 10;i++)
	{
		if(arrayofbullets[i].alive == true)
		{
			arrayofbullets[i].update();
			arrayofbullets[i].draw();
		}
	}
}

void bullets::update()
{
	ypos = ypos - 1;
}

void bullets::draw()
{
	  DrawSprite(bullet1, xpos , ypos , 20, 20);
}