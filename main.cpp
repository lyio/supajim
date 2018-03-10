//*****************************************\\
//***** Thomas Fiedler  *******************\\
//***** 28th april 2002 *******************\\
//***** main.cpp        *******************\\
//***** project: SDL    *******************\\
//*****************************************/*
#include "main.h"
#include "Class.h"
#include "map.h"


/////****** G L O B A L S ******/////////

SDL_Surface *screen;
SDL_Surface *back;
SDL_Surface *back2;
SDL_Surface *back3;
SDL_Surface *SJim;
SDL_Surface *LPSDLSCoins;

objects *coins;
Player *Jim;

int bg=1;



int main( int argc, char* argv[] )
{
  
	Uint8 *keys;
	if(SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO))
	{
		stderr;
		exit(1);
	}
	atexit(SDL_Quit);

	screen=SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
	if(!screen)
	{
		OutputDebugString("Unable to set VideoMode");
		exit(1);
	}
	//Creating object for SupJim see also class Player
	
	Jim=new Player;
	Jim->properties.x=0;
	Jim->properties.y=200;
	Jim->properties.height=50;
	Jim->properties.width=25;
	
	
	InitImages();
	DrawBG(bg);

	bool counts=false;
	bool dcounts=false;
	Jim->points=0;

	while(true)
	{
		SDL_Event event;
		SDL_Delay(20); //Waiting the time in miliseconds

		while(SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT) { exit(1);}
			if(event.type==SDL_KEYDOWN)
			{
				if(event.key.keysym.sym==SDLK_ESCAPE) {exit(1);}
			}
		}
		keys=SDL_GetKeyState(NULL);
		
		if(keys[SDLK_UP])    
		{
			counts=true;
			Jim->properties.y-=25;
		}
			
		if(counts)
		{
			Jim->properties.y+=5;
			if(Jim->properties.y==200) {counts=false;}
		}

		
		if(keys[SDLK_RIGHT]) {Jim->properties.x+=1;}
		//Jim->properties.x+=2;
		
		if(Jim->properties.x>575)
		{
			Jim->properties.x=0;
			switch(bg)
			{
			case 1: 
				{
					bg=2;
				}
				break;
			case 2:
				{
					bg=3;
				}
				break;
			case 3:
				{
					bg=1;
				}
				break;

			}
			DrawBG(bg);
		}
		DrawScene(screen,Jim);
	}

}

void DrawScene(SDL_Surface *screen,void*)
{
	
	switch(bg)
			{
			case 1: 
				{
					DrawIMG(back,Jim->properties.x-10,Jim->properties.y-10,132,132,Jim->properties.x-10,Jim->properties.y-10);
				}
				break;
			case 2:
				{
					DrawIMG(back2,Jim->properties.x-10,Jim->properties.y-10,132,132,Jim->properties.x-10,Jim->properties.y-10);
				}
				break;
			case 3:
				{
					DrawIMG(back3,Jim->properties.x-10,Jim->properties.y-10,132,132,Jim->properties.x-10,Jim->properties.y-10);
				}
				break;

			}
	
	DrawIMG(SJim,Jim->properties.x,Jim->properties.y);
	if(!coins)
	{
		coins=new coin;
		coins->properties.x=Jim->properties.x+100;
		coins->properties.height=32;
		coins->properties.width =32;

		
		if(coins->properties.x>580)
		{
			coins->properties.x=132;
		}
		coins->properties.y=225;
	}
	if(Collision(coins,Jim))
	{
		delete coins;
		coins=NULL;
		return;
	}

	DrawIMG(LPSDLSCoins,coins->properties.x,coins->properties.y);

	SDL_Flip(screen);
}
int InitImages()
{
	back 	   =SDL_LoadBMP("Graphics/bg.bmp");
	back2	   =SDL_LoadBMP("Graphics/bg2.bmp");
	back3	   =SDL_LoadBMP("Graphics/bg3.bmp");
	SJim       =SDL_LoadBMP("Graphics/SupaJim.bmp");
	LPSDLSCoins=SDL_LoadBMP("Graphics/coins.bmp");
	return 0;
}

void DrawIMG(SDL_Surface *img,int x,int y)
{
	SDL_Rect dest;
	dest.x=x;
	dest.y=y;
	SDL_BlitSurface(img,NULL,screen,&dest);
}
void DrawIMG(SDL_Surface *img,int x,int y,int w,int h,int x2,int y2)
{
	SDL_Rect dest;
	dest.x=x;
	dest.y=y;
	SDL_Rect dest2;
	dest2.x=x2;
	dest2.y=y2;
	dest2.w=w;
	dest2.h=h;
	SDL_BlitSurface(img,&dest2,screen,&dest);
}
void DrawBG(int bg)
{
	switch(bg)
	{
		case 1:
		{
			DrawIMG(back,0,0);
		}break;
		case 2:
		{
			DrawIMG(back2,0,0);
		}
		break;
		case 3:
		{
			DrawIMG(back3,0,0);
		}
		break;
	}
	
}

bool Collision(objects *obj,Player *pla)
{

	int first=0;
	int second=0;
	//starting x detection
	if((obj->properties.x<=pla->properties.x)&&(pla->properties.x<=obj->properties.x+obj->properties.width))
	{
		first=1;
	}
	if((obj->properties.x<=pla->properties.x+pla->properties.width)&&(pla->properties.x+pla->properties.width<=obj->properties.x+obj->properties.width))
	{
		first=1;
	}
	// x detection finished
	//starting y detection
	if(first)
	{
		if((obj->properties.y<=pla->properties.y+pla->properties.height)&&(pla->properties.y+pla->properties.height<=obj->properties.y+obj->properties.height))
		{
			second=1;
		}
		if((obj->properties.y<=pla->properties.y)&&(pla->properties.y<=obj->properties.y+obj->properties.height))
		{
			second=1;
		}
	}
	//y detection finished
	if(second)
	{
		return true;
		printf("Collision occured");
	}
	return false;
}

bool getMap(char* NameOfMap)
{
	struct map
	{
		char* NameOfMap;
		int   NumberOfBackgrounds;
		char* NamesOfBackgrounds;
		int   NumberOfImpassables;
	}map;
			


	
	FILE *file;
	file=fopen(NameOfMap,"r");
	if(file==NULL)
	{
		stderr;
		return 0;
	}
	
	//fscanf(file,"%s,%d,%s,%d",map.NameOfMap,map.NumberOfBackgrounds,map.NamesOfBackgrounds,map.NumberOfImpassables);
	
	OutputDebugString(map.NameOfMap);
	fclose(file);
	return 1;

}