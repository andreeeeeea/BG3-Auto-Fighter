#pragma once
#include "pch.h"
#include "Entity.cpp"
#include <iostream> 
#include <string>

using namespace std;


class GameChecker {
public:
	// This class is used for information for player characters
	void setEntity(Entity entity) {
		this->entity = entity;
	}

	// Good
	bool isHealthLow(Players player) {
		//cout << "You have " << player.getHealth() << " \ " << player.getMaxHealth() << "health." << endl;
		//if (player.getHealth() < 9) cout << "Your health is low! Either heal yourself or run away!" << endl; // placeholder for now
		// If health is low -> check if you have any healing potions or healing spells
		// If nothing to heal with -> Run as far away from the enemies, by going the opposite way from the enemies IF movement > 0
		// If movement is too low -> Check AP
		// AP != 0 -> Dash!
		// Ap == 0, end, click to go to the next turn
		// If movement > 0 
		// Constantly check the enemies around you, so you don't run into someone
		// As you run away, check the distance between the player and each enemy to make sure it is the maximum possible
		// Once again, when movement reaches 0, check your AP to see if you can dash
		return player.getHealth() < 9;
	}
	bool isDown(Players player) {
		//if (player.getHealth() == 1) cout << "Character is down! Get someone to pick them up! " << endl;
		return player.getHealth() == 1;
	}
	bool isAPEmpty(Players player) {
		//if (player.getAP() == 0) cout << "You don't have any more action points! End turn." << endl;
		//else cout << "You have " << player.getAP() << " action points." << endl;
		return player.getAP() == 0;
	}
	bool isBPEmpty(Players player) {
		//if (player.getBP() == 0) cout << "You don't have enough bonus action points!" << endl;
		//else cout << "You have " << player.getBP() << " bonus action points." << endl;
		return player.getBP() == 0;
	}
	bool isRPEmpty(Players player) {
		//if (player.getRP() == 0) cout << "You don't have enough reaction points!" << endl;
		//else cout << "You have " << player.getRP() << " reaction points." << endl;
		return player.getRP() == 0;
	}
	bool isClassResourceEmpty(int i, Players player) {
		switch (i) {
		case 0:
			return false;
			break;
		case 1:
			return player.getRage() == 0;
			break;
		case 2:
			return player.getBardInsp() == 0;
			break;
		case 3:
			return player.getChannelDivinity() == 0;
			break;
		case 4:
			return player.getWildShape() == 0;
			break;
		case 6:
			return player.getKiP() == 0;
			break;
		case 7:
			return player.getOath() == 0;
			break;
		case 9:
			return player.getSneakAttack() == 0;
			break;
		case 10:
			return player.getSorcPoint() == 0;
			break;
		case 12:
			return player.getArcaneP() == 0;
			break;
		}
	}
	bool isMovementEmpty(Players player) {
		//if (player.getMovement() == 0) cout << "Movement is empty! If you have enough AP, dash!" << endl;
		//else cout << "You have " << player.getMovement() << " movement." << endl;
		return player.getMovement() == 0;
	}

	// But also for enemy characters
	bool isEnemyHealthLow(Enemies enemy) {
		//cout << "This enemy has " << enemy.getHealth() << " \ " << enemy.getMaxHealth() << "health." << endl;
		//if (enemy.getHealth() < 5) cout << "This enemy's health is low! If they're close-by, focus on them and take them out before they heal!" << endl;
		return enemy.getHealth() < 5;
	}
	bool isEnemyClose(Players player, Enemies enemy) {
		float x_Current = player.getXCoord();
		float z_Current = player.getZCoord();
		float y_Current = player.getYCoord();
		float x_Target = enemy.getXCoord();
		float z_Target = enemy.getZCoord();
		float y_Target = enemy.getYCoord();
		float distance = sqrt((pow(abs(x_Current - x_Target), 2)) + (pow(abs(z_Current - z_Target), 2)) + (pow(abs(y_Current - y_Target), 2)));
		return distance <= 1;
	}
	void getClosestEnemy(Players player, Enemies& enemy, Entity entity) {
		float min_Distance = INT_MAX;
		float x_Target, z_Target, y_Target;

		for (int i = 0; i < entity.getEnemies().size(); i++) {
			float distance = sqrt((pow(abs(player.getXCoord() - entity.getEnemies()[i].getXCoord()), 2)) +
				(pow(abs(player.getZCoord() - entity.getEnemies()[i].getZCoord()), 2)) +
				(pow(abs(player.getYCoord() - entity.getEnemies()[i].getYCoord()), 2)));
			if (distance < min_Distance) {
				min_Distance = distance;
				enemy = entity.getEnemies()[i];
				x_Target = round(entity.getEnemies()[i].getXCoord());
				z_Target = round(entity.getEnemies()[i].getZCoord());
				y_Target = round(entity.getEnemies()[i].getYCoord());
			}
		}
	}
	bool isClose(Players player, Enemies enemy) {
		float distance = getDistance(player, enemy);
		return distance <= 1;
	}
	float getDistance(Players player, Enemies enemy) {
		float x_Current, z_Current, y_Current;
		float x_Target, z_Target, y_Target;
		x_Current = player.getXCoord();
		y_Current = player.getYCoord();
		x_Target = enemy.getXCoord();
		y_Target = enemy.getYCoord();
		float distance = sqrt((pow(abs(x_Target - x_Current), 2)) + (pow(abs(y_Target - x_Current), 2)));
		return distance;
	}


private:
	Entity entity;
    uintptr_t baseAddress;
};