#ifndef __CLASS_HEADER
#define __CLASS_HEADER

class Player
{
public:
	Player()
	{
		//Constructor
		int maxJumpHeight=150; //y-position 
	}
	int points;
	struct properties
	{
		int x,y,height,width;
	}properties;
	
};

class objects
{
public:
	objects()
	{
		//Constructor
	}
	struct properties
	{
		int x,y,height,width;
	}properties;
};


class coin:public objects
{
public:
	coin()
	{
		//Constructor
		properties.y=225;
	}

	
};
class enemy:public objects
{
public:
	enemy()
	{
		//Constructor
		properties.y=225;
	}
};

#endif