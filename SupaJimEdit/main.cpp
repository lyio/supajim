//*****************************************************\\
//***** Thomas Fiedler              *******************\\
//***** 20th may 2002               *******************\\
//***** main.cpp                    *******************\\
//***** project: SupaJimEdit 1.0    *******************\\
//*****************************************************/*
#include <stdio.h>
#include <stdlib.h>
#define HELP 1
#define SAVE 2
#define OPEN 3
#define EXIT 4
//#define 

int  save(char* name);
int  open(char* name,char* rights);
void welcome();
void help();

int main(/*int argc,*/ char* argv[])
{
	int scan;
	welcome();
	while(1)
	{
		scanf("Bitte eingebenb:%d",scan);
		
		if(scan==HELP){help();}
		if(scan==EXIT){return 0;}
		//if(scan==OPEN){open(name);}
		//if(scan==SAVE){save(name);}
/*
		switch(scan)
		{
			case HELP:
			{
				help();
			}
			break;
			case EXIT:
			{
				exit(0);
			}
			break;
			case SAVE:
			{	
				char* name;
				scanf("Please endter the file name: %s",name);
				save(name);
			}
			break;
			case OPEN:
			{
				//open(djkfhnjkd);
			}
			break;
		}*/


	}

}

int save(char* name)
{
	FILE *file;
	fopen(name,"w");

	if(file==NULL)
	{
		printf("Couldn't (f)open file");
		return 0;
	}
}
int open(char* name,char* rights)
{
	FILE *file;
	return 0;
}
void welcome()
{
	printf("Welcome to the level editor of SupaJim. Well it's a very primitive one so enjoy yourself. For help just type '1' (without the quotes)");
	getchar();
}
void help()
{
	printf("\n\n\n");
	printf("So here we are...");
}