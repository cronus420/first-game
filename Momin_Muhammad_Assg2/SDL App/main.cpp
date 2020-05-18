// SDL_App.cpp : Defines the entry point for our Project
//
#include <Windows.h>
#include "GL_Functions.h"
#include "pctimer.h"
#include <string>
#include <cmath>
#include <crtdbg.h>

float enemyxpos= 512.0;
float enemyypos= 384.0;	
float enemyvosx = 1.0;
float enemyvosy = 1.0;

//--------------------------------------------------------------DECLARATIONS for Bullets--------------------------------------------------------------//	
struct Enemy 
{
	


	void draw()
	{
	
		int Enemy = LoadTexture("./images/alienblaster.png");
		DrawSprite(Enemy, enemyxpos, enemyypos , 76, 76);
	}


	void update()
	{
	
	   
	if(   enemyxpos < 0  ||   enemyxpos > 1024  )
	{ 

		enemyxpos*=-1;

	}

	if(   enemyypos < 0 ||   enemyypos > 768  )

	{ 

		enemyxpos*=-1;

	}


	enemyxpos+=enemyvosx;
	enemyypos+=enemyvosy;

	
	}
};	




Enemy enemy; 

int main(int argc, char* argv[])
{
	//Lets open the window and initialise opengl
	InitGL(1024,768);
	


	//Loads an Image, stored in as a integer 
	int grass = LoadTexture("./images/firststars.png");
	int player= LoadTexture("./images/kspaceduel.png");
	int background= LoadTexture("./images/background.png");

	int counter=0;
	int frame=0;
	int guncooldown= 0;
	
	//--------------------------------------------------------------Creating GRID--------------------------------------------------------------	
	do
	{ 
		//Clear the screen, so previous frames don't build up
		ClearScreen();
			
		for(int j=0; j<10; j++)
		{	       							
			for( int k=0; k<10; k++)
			{
		   		DrawSprite(grass, 128 * j , 128 * k , 128, 128);
			}
		}
		
		DrawSprite(background, 0 , 0 , 1024, 768);
		DrawSprite(player, GetMouseX() , GetMouseY() , 76, 76);

	  
		

		//Update/Draw
		frame++;
		guncooldown= 0;

			
	
		
		enemy.draw();
		enemy.update();
		
		
		

		//Stop it from running too fast! Sleep ZZzzz

		Sleep(5);
		
	} while (FrameworkUpdate()); //Do some secret stuff, 

	//Before you exit, clean up after yourself
	FreeTexture(grass);
	//Close down
	CloseDown();

	_CrtDumpMemoryLeaks();

	//Quit!
	return 0;

}


