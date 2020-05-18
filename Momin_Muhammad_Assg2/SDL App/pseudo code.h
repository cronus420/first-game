// SDL_App.cpp : Defines the entry point for our Project
//
#include "stdafx.h"
#include <Windows.h>
#include "GL_Functions.h"
#include "pctimer.h"
#include <string>
#include <cmath>
#include <crtdbg.h>

float ball_x= 1024 * 0.5f;
float ball_y= 768 * 0.5f;
	

int main(int argc, char* argv[])
{

	//Lets open the window and initialise opengl
	InitGL(1024,768);
	
	
	//Loads an Image, stored in as a integer 
	int grass = LoadTexture("./images/firststars.png");
	int paddle_2= LoadTexture("./images/paddle.png");
	int paddle_1= LoadTexture("./images/paddle.png");
	int ball = LoadTexture("./images/ball.png");
	int background= LoadTexture("./images/background.png");
	
	
	
	
	
	
	// used values 
	float x = 100;
	float y = 100;
	float mov_1 = 0;
	float mov_2 = 0;
	float ballspeed_x= 0.8;
	float ballspeed_y= 1;

	float paddle_1_x = 30;
	float paddle_1_y = 0;
	float paddle_1_h = 150;
	float paddle_2_x = 975;
	float paddle_2_y = 0;
	float paddle_2_h = 150;
	
	
	
	
	
	
	;
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




//------------------------------------------------------------MOVEMENT OF THE BALL---------------------------------------------------------------	
		

	   
	if(  ball_x<0  ||   ball_x>1024  )
	{ 

		ballspeed_x*=-1;

	}

	if(   ball_y<0 ||   ball_y >768  )

	{ 

		ballspeed_y*=-1;

	}


	ball_x+=ballspeed_x;
	ball_y+=ballspeed_y;


//---------------------------------------------------------MOVEMENT OF THE PADDLE----------------------------------------------------------------



		if (IsKeyDown('w') && mov_1 > 0 )
			
			mov_1 -= 3.0f; 
     

		
		if (IsKeyDown('s') && mov_1+paddle_1_h < 768)
		
			mov_1 += 3.0f;
				
				
		if (IsKeyDown(KEY_UP) && mov_2 > 0)
			mov_2 -= 3.0f;		
		
		
		if (IsKeyDown(KEY_DOWN) && mov_2+paddle_1_h < 768)
		    mov_2 += 3.0f;

		
		
		if(IsKeyDown(KEY_ESCAPE))
			break;
			
		//Draw sprite 
		
		DrawSprite(ball, ball_x, ball_y, 30, 30);
		DrawSprite(paddle_1, 30, mov_1, 30, paddle_1_h);
		DrawSprite(paddle_2, 975, mov_2, 30, paddle_1_h);
		DrawString("COME AT ME!!", x-60, y-80, 5.0f);
		 
		
//---------------------------------------------------------Collsion OF THE PADDLE----------------------------------------------------------------
		


}
 //Left
 if( ball_x < (paddle_1_x + 30 ))
	 { 
			if(	( ball_y < ( mov_1 + paddle_1_h )  && ( ball_y ) > mov_1 )  )
			{
				if ( ballspeed_x < 0)
				{
					ballspeed_x *= -1;
				    ballspeed_x += 0.9f;
					ballspeed_y += 0.6f;
				}
			}
	}
 //Right
 else if( ball_x + 30 > paddle_2_x)
	{
		if( ball_y > mov_2  && ball_y < mov_2 + paddle_1_h)
		{
			if ( ballspeed_x > 0)
			{
				ballspeed_x *= -1;
				ballspeed_x += 0.9f;
				ballspeed_y += 0.06f;
			}
		}
	}




		
		
//---------------------------------------------------------0-----------------------------------------------------------------------------------		
void playerscore()
{
	
	DrawString("Player 1 =  ", 70, 70, 3.0f)
	DrawString("Player 2 =  ", 70, 770, 3.0f)
	
	
	
	
	
	
	
	int p1=0;
	int p2=0;

		if ( ball_x<0  )
		{ 
           while(p1<10)   
			{p1++}

		}

		else if(   ball_x>1024 )

		{ 
            while(p2<10)    
			{p2++}

		}
}
		 	
		
		
		
		
		
		//Stop it from running too fast! Sleep ZZzzz

		Sleep(5);
		
	} while (FrameworkUpdate()); //Do some secret stuff, 

	//Before you exit, clean up after yourself
	FreeTexture(grass);
	FreeTexture(paddle_1);
	FreeTexture(paddle_2);
	//Close down
	CloseDown();

	_CrtDumpMemoryLeaks();

	//Quit!
	return 0;
}

