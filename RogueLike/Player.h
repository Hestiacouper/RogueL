#pragma once
#include <iostream>
class Player
{
public:
	int posX = 1;
	int posY = 1;
	int oldPosX = posX;
	int oldPosY = posY;
	std::string playerInput;
	Player();

	void takeDamage(int damage);
	void gainHealth(int health);
	void playerAction(int obstacle, int damage, int heal);
	//void playerSetPos(int obstacle,int posX, int posY, std::string playerInput);
	void drinkPotion(int heal);
	void printPlayerInfo();
	int getPlayerHealth();
private:
	int playerHealth_ = 5;
	int playerPots_ = 0;
	int playerMaxHealth_ = 5;
};