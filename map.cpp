//*****************************************\\
//***** Thomas Fiedler  *******************\\
//***** 20th may 2002   *******************\\
//***** map.cpp         *******************\\
//***** project: SDL    *******************\\
//*****************************************/*
/*
#include "map.h"


bool getMap(char* NameOfMap)
{
	struct map
	{
		char* NameOfMap;
		int   NumberOfBackgrounds;
		char* NamesOfBackgrounds;
		char* eop;
		
		int   NumberOfImpassables;
		
		struct impass
		{
			int x,y,height,width;
			char* KindOfObject;
		}impass;

	}map;
			


	
	FILE *file;
	file=fopen(NameOfMap,"r");
	if(file==NULL)
	{
		OutputDebugString("Couldn't (f)open file");
		OutputDebugString(NameOfMap);
		return 0;
	}
	//fscanf(file,"%s,%d,%s,%d",map.NameOfMap,map.NumberOfBackgrounds,map.NamesOfBackgrounds,map.NumberOfImpassables);
	//fgets(map.NameOfMap,11,file);
	
	OutputDebugString(map.NameOfMap);
	fclose(file);


	return 1;

}
*/