#include "pch.h"
#include <vector>
#include <algorithm>
#include "Players.cpp"
#include "Enemies.cpp"

using namespace std;

#pragma once

class Entity {
public:
	Entity() {
		playerCharacters = vector<Players>();
		enemyCharacters = vector<Enemies>();
	}
	// Setters (kinda?)
	void addPlayers(Players character) {
		playerCharacters.push_back(character);
	}
	void addEnemies(Enemies character) {
		enemyCharacters.push_back(character);
	}

	void clearVectors() {
		playerCharacters.clear();
		enemyCharacters.clear();
	}

	// Getters 
	vector<Players> getPlayers() {
		return playerCharacters;
	}
	vector<Enemies> getEnemies() {
		return enemyCharacters;
	}

private:
	vector<Players> playerCharacters;
	vector<Enemies> enemyCharacters;
};