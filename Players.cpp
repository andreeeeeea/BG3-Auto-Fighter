#pragma once
#include "pch.h"
#include <unordered_map> 
#include <string>
#include <iostream>
#ifndef Players_HEADER
#define Players_HEADER

using namespace std;

class Players {
public:
    Players() {
        health = maxHealth = 0;
        movement = 0;
        x_coord = z_coord = y_coord = 0;
        //charClass = vector<int>(1, 0);
        firstClass = secondClass = 0;
        AP = BP = RP = 0;
        bardInsp = rage = wildShape = sneakAttack = kiP = arcaneP = superiorityDie = luckPoints = channelDivinity = tidesChaos = sorceryPoint = channelOath = 0;
    }

    // Getters
    double getHealth() {
        return health;
    }
    double getMaxHealth() {
        return maxHealth;
    }
    double getMovement() {
        return movement;
    }
    int getFirstClass() {
        return firstClass;
    }
    int getSecondClass() {
        return secondClass;
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
    double getAP() {
        return AP;
    }
    double getBP() {
        return BP;
    }
    double getRP() {
        return RP;
    }
    double getBardInsp() {
        return bardInsp;
    }
    double getRage() {
        return rage;
    }
    double getWildShape() {
        return wildShape;
    }
    double getSneakAttack() {
        return sneakAttack;
    }
    double getKiP() {
        return kiP;
    }
    double getChannelDivinity() {
        return channelDivinity;
    }
    double getChaos() {
        return tidesChaos;
    }
    double getSorcPoint() {
        return sorceryPoint;
    }
    double getOath() {
        return channelOath;
    }
    double getArcaneP() {
        return arcaneP;
    }
    double getSuperiorityDie() {
        return superiorityDie;
    }
    double getLuckPoints() {
        return luckPoints;
    }

    // Setters
    void setHealth(double health) {
        this->health = health;
    }
    void setMaxHealth(double maxHealth) {
        this->maxHealth = maxHealth;
    }
    void setMovement(double movement) {
        this->movement = movement;
    }
    void setFirstClass(int firstClass) {
        this->firstClass = firstClass;
    }
    void setSecondClass(int secondClass) {
        this->secondClass = secondClass;
    }
    /**void setFirstClass(int i) {
        this->charClass[0] = i;
    }
    void setSecondClass(int i) {
        charClass.push_back(i);
    }**/

    void setCoordinates(float x_coord, float z_coord, float y_coord) {
        this->x_coord = x_coord;
        this->z_coord = z_coord;
        this->y_coord = y_coord;
    }
    void setAP(double AP) {
        this->AP = AP;
    }
    void setBP(double BP) {
        this->BP = BP;
    }
    void setRP(double RP) {
        this->RP = RP;
    }
    void setBardInsp(double bardInsp) {
        this->bardInsp = bardInsp;
    }
    void setRage(double rage) {
        this->rage = rage;
    }
    void setWildShape(double wildShape) {
        this->wildShape = wildShape;
    }
    void setSneakAttack(double sneakAttack) {
        this->sneakAttack = sneakAttack;
    }
    void setKiP(double kiP) {
        this->kiP = kiP;
    }
    void setArcaneP(double arcaneP) {
        this->arcaneP = arcaneP;
    }
    void setChannelDivinity(double channelDivinity) {
        this->channelDivinity = channelDivinity;
    }
    void setChaos(double tidesChaos) {
        this->tidesChaos = tidesChaos;
    }
    void setSorcPoint(double sorceryPoint) {
        this->sorceryPoint = sorceryPoint;
    }
    void setOath(double channelOath) {
        this->channelOath = channelOath;
    }
    void setSuperiorityDie(double superiorityDie) {
        this->superiorityDie = superiorityDie;
    }
    void setLuckPoints(double luckPoints) {
        this->luckPoints = luckPoints;
    }

    // Not setters or getters
    /**
    string setClassName(int i) {
        string charClass;
        switch (i) {
        case 0:
            charClass = "No class";
            break;
        case 1:
            charClass = "Barbarian";
            break;
        case 2:
            charClass = "Bard";
            break;
        case 3:
            charClass = "Cleric";
            break;
        case 4:
            charClass = "Druid";
            break;
        case 5:
            charClass = "Fighter";
            break;
        case 6:
            charClass = "Monk";
            break;
        case 7:
            charClass = "Paladin";
            break;
        case 8:
            charClass = "Ranger";
            break;
        case 9:
            charClass = "Rogue";
            break;
        case 10:
            charClass = "Sorcerer";
            break;
        case 11:
            charClass = "Warlock";
            break;
        case 12:
            charClass = "Wizard";
            break;
        }
        return charClass;
    }
    vector<string> getClasses() {
        int firstClassNumber = firstClass;
        string firstClassName = setClassName(firstClassNumber);
        charClass.push_back(firstClassName);
        if (secondClass != 0) {
            int secondClassNumber = secondClass;
            string secondClass = setClassName(secondClassNumber);
            charClass.push_back(secondClass);
        }
        return charClass;
    }**/

    void displayInformation() {
        cout << endl;
        cout << "                      [*] " << health << " health and " << maxHealth << " max health." << endl;
        //if (charClass.size() == 1) cout << "                      [*] " << "Your character is one class: " << charClass[0] << endl;
        //else cout << "                      [*] " << "Your character is two classes: " << charClass[0] << " and " << charClass[1] << endl;
        cout << "                      [*] " << AP << " action points, " << BP << " bonus action points and " << RP << " reaction points." << endl;
        if (bardInsp != 0) cout << "                      [*] " << bardInsp << " bard points." << endl;
        if (rage != 0) cout << "                      [*] " << rage << " rage points." << endl;
        if (wildShape != 0) cout << "                      [*] " << wildShape << " wild shape points." << endl;
        if (sneakAttack != 0) cout << "                      [*] " << sneakAttack << " sneak attack charges." << endl;
        if (kiP != 0) cout << "                      [*] " << kiP << " ki points." << endl;
        if (arcaneP != 0) cout << "                      [*] " << arcaneP << " arcane recovery points." << endl;
        if (channelDivinity != 0) cout << "                      [*] " << channelDivinity << " channel divinity points." << endl;
        if (tidesChaos != 0) cout << "                      [*] " << tidesChaos << " tides of chaos points." << endl;
        if (sorceryPoint != 0) cout << "                      [*] " << sorceryPoint << " sorcery points." << endl;
        if (superiorityDie != 0) cout << "                      [*] " << superiorityDie << " superiority dice." << endl;
        if (luckPoints != 0) cout << "                      [*] " << luckPoints << " luck points." << endl;
        cout << "                      [*] Is at coordinates x: " << x_coord << " z: " << z_coord << " y: " << y_coord << endl;
        cout << "                      [*] " << movement << " movement." << endl;
        cout << endl;
    }

private:
    double health, maxHealth;
    double movement;
    float x_coord, z_coord, y_coord;
    // 0 -> No class
    // 1 -> barbarian
    // 2 -> bard
    // 3 -> cleric
    // 4 -> druid
    // 5 -> fighter
    // 6 -> monk
    // 7 -> paladin
    // 8 -> Ranger
    // 9 -> Rogue
    // 10 -> Sorcerer
    // 11 -> Warlock
    // 12 -> Wizard
    //vector<int> charClass;
    //vector<string> charClass;
    int firstClass, secondClass;
    double AP, BP, RP; // action points, bonus points - base kit, for all characters
    double bardInsp, rage, wildShape, sneakAttack, kiP, arcaneP, channelDivinity, tidesChaos, sorceryPoint, channelOath;
    // class based resources for: bard, barbarian, druid, rogue, monk, wizard, cleric
    double superiorityDie, luckPoints; // skill based resources
    // will add more stats here as I go
};

#endif