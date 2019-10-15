#include "pch.h"
#include "Map.h"
#include "Obstacle.h"
#include <iostream>

Map::Map(int posX, int posY)
{
	map_ = std::vector<std::vector<char> >(map_width, std::vector<char>(map_height));
	for (int i = 0; i < map_.size(); i++)
	{
		for (unsigned int j = 0; j < map_[i].size(); j++)
		{
			map_[i][j] = Obstacle::ground;
		}
	}

	for (unsigned int i = 0; i < map_height; i++)
	{
		map_[0][i] = Obstacle::borderHorizontal;
		map_[map_width - 1][i] = Obstacle::borderHorizontal;
	}

	for (unsigned int i = 0; i < map_width; i++)
	{
		map_[i][0] = Obstacle::borderVertical;
		map_[i][map_height - 1] = Obstacle::borderVertical;
	}

	

	map_[posY][posX] = Obstacle::player;

}

int Map::checkTile(int posX, int posY)
{
	switch (map_[posX][posY])
	{
	case Obstacle::ground:
	{
		return 1;
	}

	case Obstacle::potion:
	{
		return 2;
	}
	case Obstacle::trap:
	{
		return 3;
	}
	case Obstacle::borderHorizontal:
	{
		return 4;
	}
	case Obstacle::borderVertical:
	{
		return 4;
	}
	case Obstacle::moutain:
	{
		return 4;
	}
	}
}


void Map::setPlayerPos(int tile, int posX, int posY, int oldPosX, int oldPosY)
{
	map_[oldPosX][oldPosY] == Obstacle::ground;
	map_[posX][posY] == Obstacle::player;
}

/*void Map::setTile(int tile, int posX, int posY)
{
	if (tile == 1)
	{
		map_[posX][posY] == Obstacle::ground;
	}
}*/


void Map::printMap()
{
	system("cls");
	for (int i = 0; i < map_.size(); i++)
	{
		for (int j = 0; j < map_[i].size(); j++)
		{
			std::cout << map_[i][j];
		}
		std::cout << "\n";
	}
}