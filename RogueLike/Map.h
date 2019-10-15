#pragma once
#include <vector>

class Map
{
public:
	
	const int map_height = 16;
	const int map_width = 16;
	Map(int posX, int posY);
	int checkTile(int posX, int posY);
	void setPlayerPos(int tile, int posX, int posY, int newPosX, int newPosY);
	//void setTile(int tile, int posX, int posY);
	void printMap();

private:
	std::vector<std::vector<char> > map_;
};

