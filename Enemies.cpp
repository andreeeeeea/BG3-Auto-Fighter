#include "pch.h"

class Enemies {
public:
    Enemies() {
        health = maxHealth = 0;
        x_coord = z_coord = y_coord = 0;
    }
    // Getters
    double getHealth() {
        return health;
    }
    double getMaxHealth() {
        return maxHealth;
    }
    float getXCoord() {
        return x_coord;
    }
    float getZCoord() {
        return z_coord;
    }
    float getYCoord() {
        return y_coord;
    }

    // Setters
    void setHealth(double health) {
        this->health = health;
    }
    void setMaxHealth(double maxHealth) {
        this->maxHealth = maxHealth;
    }
    void setCoordinates(float x_coord, float z_coord, float y_coord) {
        this->x_coord = x_coord;
        this->z_coord = z_coord;
        this->y_coord = y_coord;
    }

private:
    double health, maxHealth;
    float x_coord, z_coord, y_coord;
    // will add more stats here as I go
};