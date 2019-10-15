#include "pch.h"
#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Obstacle.h"

void Game::run()
{
	
	bool isRunning = true;
	Player player = Player();
	Map map = Map(player.posX, player.posY);
	int heal = 1;
	int damage = 1;
	std::string playerInput;


	while (isRunning)
	{
		map.printMap();
		player.printPlayerInfo();
		
		
		int obstacle = map.checkTile(player.posX, player.posY);
		std::cout << "Choose your action, wasd to moove, f to drink a potion, e to pickup a potion \n";
		map.setPlayerPos(obstacle, player.posX, player.posY, player.oldPosX, player.oldPosY);
		player.playerAction(obstacle, damage, heal);
		
	}

}

