#ifndef __MAIN_HEADER
#define __MAIN_HEADER

//*****************************************\\
//***** Thomas Fiedler  *******************\\
//***** 28th april 2002 *******************\\
//***** main.h          *******************\\
//***** project: SDL    *******************\\
//*****************************************/*

#include <stdio.h>
#include <stdlib.h>
#include <SDL\SDL.h>
#include <windows.h>
#include "Class.h"
#define WIN32_LEAN_AND_MEAN

// ****** P R O T O T Y P E S *************

bool Init();
void SLock (SDL_Surface* screen);
void SuLock(SDL_Surface* screen);
void DrawPixel(SDL_Surface* screen,int x,int y,Uint8 R,Uint8 G,Uint8 B);
void DrawScene(SDL_Surface* screen,void*);
int  InitImages();
void DrawIMG(SDL_Surface *img,int x,int y);
void DrawIMG(SDL_Surface *img,int x,int y,int w,int h,int x2,int y2);
void DrawBG(int bg);
bool Collision(objects *obj,Player *pla);

#endif