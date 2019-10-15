#include "pch.h"
#include "Player.h"
#include <iostream>
Player::Player()
{
	
}

void Player::takeDamage(int damages)
{
	playerHealth_ -= damages;
}

void Player::gainHealth(int heal)
{
	playerHealth_ += heal;

	if(playerHealth_>playerMaxHealth_)
	{
		playerHealth_ = playerMaxHealth_;
		
	}
}

void Player::playerAction(int obstacle, int damage, int heal)
{
	std::cin>> playerInput;
	if (playerInput == "f"&&playerPots_>0)
	{
		if(playerHealth_==playerMaxHealth_)
		{
			std::cout << "You wasted a potion, teehee :p";
		}
		Player::drinkPotion(heal);
	}
	else if(playerInput=="e"&&obstacle==2)
	{
		
		playerPots_ += 1;
	}
	if (playerInput == "w"&&obstacle != 4)
	{
		oldPosY = posY;
		posY -= 1;
	}
	else if (playerInput == "s"&&obstacle != 4)
	{
		oldPosY = posY;
		posY += 1;
	}
	else if (playerInput == "a"&&obstacle != 4)
	{
		oldPosX = posX;
		posX -= 1;
	}
	else if (playerInput == "d"&&obstacle != 4)
	{
		oldPosX = posX;
		posX += 1;
	}
	else
	{
		playerAction(obstacle, damage, heal);
	}

}

void Player::drinkPotion(int heal)
{
	Player::gainHealth(heal);
}


void Player::printPlayerInfo()
{
	std::cout << "Player health is : " << playerHealth_ << "\n";
	std::cout << "Player has " << playerPots_ << " potions \n";
}







