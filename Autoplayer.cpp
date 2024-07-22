#pragma once
#include "pch.h"
#include "GameChecker.cpp"
#include "Controller.cpp"
#include <iostream> 
#include <iomanip>
#include <string>

using namespace std;

class Autoplayer {
public:

    void getCoordinates(uintptr_t baseAddress, Players& character, uintptr_t sixthOffset_Coordinates, int counter) {
        __try {

            if (counter == 1) {
                float* seventhOffset_Coordinates_x = (float*)(sixthOffset_Coordinates + 0x9A0);
                float* seventhOffset_Coordinates_z = (float*)(sixthOffset_Coordinates + 0x9A4);
                float* seventhOffset_Coordinates_y = (float*)(sixthOffset_Coordinates + 0x9A8);
                float x_Coordinate = *seventhOffset_Coordinates_x;
                float z_Coordinate = *seventhOffset_Coordinates_z;
                float y_Coordinate = *seventhOffset_Coordinates_y;
                character.setCoordinates(x_Coordinate, z_Coordinate, y_Coordinate);

            }
            else if (counter == 2) {
                float* seventhOffset_Coordinates_x = (float*)(sixthOffset_Coordinates + 0x9B0);
                float* seventhOffset_Coordinates_z = (float*)(sixthOffset_Coordinates + 0x9B4);
                float* seventhOffset_Coordinates_y = (float*)(sixthOffset_Coordinates + 0x9B8);
                float x_Coordinate = *seventhOffset_Coordinates_x;
                float z_Coordinate = *seventhOffset_Coordinates_z;
                float y_Coordinate = *seventhOffset_Coordinates_y;
                character.setCoordinates(x_Coordinate, z_Coordinate, y_Coordinate);

            }
            else if (counter == 3) {
                float* seventhOffset_Coordinates_x = (float*)(sixthOffset_Coordinates + 0x9C0);
                float* seventhOffset_Coordinates_z = (float*)(sixthOffset_Coordinates + 0x9C4);
                float* seventhOffset_Coordinates_y = (float*)(sixthOffset_Coordinates + 0x9C8);
                float x_Coordinate = *seventhOffset_Coordinates_x;
                float z_Coordinate = *seventhOffset_Coordinates_z;
                float y_Coordinate = *seventhOffset_Coordinates_y;
                character.setCoordinates(x_Coordinate, z_Coordinate, y_Coordinate);

            }
            else if (counter == 4) {
                float* seventhOffset_Coordinates_x = (float*)(sixthOffset_Coordinates + 0x9D0);
                float* seventhOffset_Coordinates_z = (float*)(sixthOffset_Coordinates + 0x9D4);
                float* seventhOffset_Coordinates_y = (float*)(sixthOffset_Coordinates + 0x9D8);
                float x_Coordinate = *seventhOffset_Coordinates_x;
                float z_Coordinate = *seventhOffset_Coordinates_z;
                float y_Coordinate = *seventhOffset_Coordinates_y;
                character.setCoordinates(x_Coordinate, z_Coordinate, y_Coordinate);

            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}

    } // this should work like this
    void getHealth(uintptr_t baseAddress, Players& character, uintptr_t thirdOffset_Health, unsigned int j) {

        uintptr_t fourthOffset_Health = *(uintptr_t*)(thirdOffset_Health + j);
        __try {
            uintptr_t fifthOffset_Health = *(uintptr_t*)(fourthOffset_Health + 0xE0); //0x68, 0x20
            uintptr_t sixthOffset_Health = *(uintptr_t*)(fifthOffset_Health + 0x58); //0xE0, 0xE0 -                
            double* seventhOffset_Health = (double*)(sixthOffset_Health + 0x78); //0x48      
            double* seventhOffset_HealthMax = (double*)(sixthOffset_Health + 0x88); //0x48  
            double health = *seventhOffset_Health;
            double maxHealth = *seventhOffset_HealthMax;

            character.setHealth(health);
            character.setMaxHealth(maxHealth);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}

    }
    void getResources(uintptr_t baseAddress, Players& character, uintptr_t thirdOffset_Resources, unsigned int j) {

        // 1 -> action point
        // 2 -> bonus action
        // 3 -> reaction point
        // 4+ -> depends on class and choices
        // The characters in this are in the same order as the health -> good.

        uintptr_t fourthOffset_Resources = *(uintptr_t*)(thirdOffset_Resources + j);
        uintptr_t fifthOffset_Resources = *(uintptr_t*)(fourthOffset_Resources + 0xE0);
        uintptr_t sixthOffset_Resources = *(uintptr_t*)(fifthOffset_Resources + 0x2A8);
        uintptr_t seventhOffset_Resources = *(uintptr_t*)(sixthOffset_Resources + 0x18);
        for (unsigned int k = 0x0000; k <= 0x0030; k += 0x0008) {
            __try {
                uintptr_t eighthOffset_Resources = *(uintptr_t*)(seventhOffset_Resources + k);
                double* ninthOffset_Resources = (double*)(eighthOffset_Resources + 0x50);
                char* ninthOffset_Resources_Name = (char*)eighthOffset_Resources + 0x120; // Gets the name of the resource
                double resource = *ninthOffset_Resources;
                //string resource_Name = *ninthOffset_Resources_Name;

                if (strcmp(ninthOffset_Resources_Name, "ActionPoint") == 0) character.setAP(resource);
                else if (strcmp(ninthOffset_Resources_Name, "BonusActionPoint") == 0) {
                    character.setBP(resource);
                }
                else if (strcmp(ninthOffset_Resources_Name, "ReactionActionPoint") == 0) {
                    character.setRP(resource);
                }
                else if (strcmp(ninthOffset_Resources_Name, "BardicInspiration") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(2);
                    else character.setSecondClass(2);
                    character.setBardInsp(resource);
                    //if (character.getClassValue("Bard") == false) character.setClass("Bard");
                }
                else if (strcmp(ninthOffset_Resources_Name, "Rage") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(1);
                    else character.setSecondClass(1);
                    character.setRage(resource);
                    // if (character.getClassValue("Barbarian") == false) character.setClass("Barbarian");
                }
                else if (strcmp(ninthOffset_Resources_Name, "WildShape") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(4);
                    else character.setSecondClass(4);
                    character.setWildShape(resource);
                    // if (character.getClassValue("Druid") == false) character.setClass("Druid");
                }
                else if (strcmp(ninthOffset_Resources_Name, "SneakAttack_Charge") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(9);
                    else character.setSecondClass(9);
                    character.setSneakAttack(resource); // check again for the name
                    // if (character.getClassValue("Rogue") == false) character.setClass("Rogue");
                }
                else if (strcmp(ninthOffset_Resources_Name, "KiPoint") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(6);
                    else character.setSecondClass(6);
                    character.setKiP(resource);
                    //  if (character.getClassValue("Monk") == false) character.setClass("Monk");
                }
                else if (strcmp(ninthOffset_Resources_Name, "ChannelDivinity") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(3);
                    else character.setSecondClass(3);
                    character.setChannelDivinity(resource);
                    // if (character.getClassValue("Cleric") == false) character.setClass("Cleric");
                }
                else if (strcmp(ninthOffset_Resources_Name, "TidesOfChaos") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(10);
                    else character.setSecondClass(10);
                    character.setChaos(resource);
                    //if (character.getClassValue("Sorcerer") == false) character.setClass("Sorcerer");
                }
                else if (strcmp(ninthOffset_Resources_Name, "SorceryPoint") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(10);
                    else character.setSecondClass(10);
                    character.setSorcPoint(resource);
                    //if (character.getClassValue("Sorcerer") == false) character.setClass("Sorcerer");
                }
                else if (strcmp(ninthOffset_Resources_Name, "ArcaneRecoveryPoint") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(12);
                    else character.setSecondClass(12);
                    character.setArcaneP(resource);
                    // if (character.getClassValue("Wizard") == false) character.setClass("Wizard");
                }
                else if (strcmp(ninthOffset_Resources_Name, "ChannelOathCharge") == 0) {
                    if (character.getFirstClass() == 0) character.setFirstClass(7);
                    else character.setSecondClass(7);
                    character.setOath(resource);
                    //  if (character.getClassValue("Paladin") == false) character.setClass("Paladin");
                }
                else if (strcmp(ninthOffset_Resources_Name, "LuckPoint") == 0) character.setLuckPoints(resource); // check again for the name
                else if (strcmp(ninthOffset_Resources_Name, "SuperiorityDie") == 0) character.setSuperiorityDie(resource); // check again for the name;
                else if (strcmp(ninthOffset_Resources_Name, "LuckPoint") == 0) character.setLuckPoints(resource); // check again for the name
            }
            __except (EXCEPTION_EXECUTE_HANDLER) {}
        }
    }
    void getMovement(uintptr_t baseAddress, Players& character, uintptr_t thirdOffset_Movement, unsigned int j) {
        __try {
            uintptr_t fourthOffset_Movement = *(uintptr_t*)(thirdOffset_Movement + j);
            uintptr_t fifthOffset_Movement = *(uintptr_t*)(fourthOffset_Movement + 0xE0);
            uintptr_t sixthOffset_Movement = *(uintptr_t*)(fifthOffset_Movement + 0x260);
            double* seventhOffset_Movement = (double*)(sixthOffset_Movement + 0x50);
            double movement = *seventhOffset_Movement;

            character.setMovement(movement);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}

    }
    void getParty(int counter, uintptr_t baseAddress) {
        __try {
            uintptr_t listAddress_Coordinates = *(uintptr_t*)(baseAddress + 0x050A0B10);
            uintptr_t firstOffset_Coordinates = *(uintptr_t*)(listAddress_Coordinates + 0x40);
            uintptr_t secondOffset_Coordinates = *(uintptr_t*)(firstOffset_Coordinates + 0x60);
            uintptr_t thirdOffset_Coordinates = *(uintptr_t*)(secondOffset_Coordinates + 0x70);
            uintptr_t fourthOffset_Coordinates = *(uintptr_t*)(thirdOffset_Coordinates + 0x80);
            uintptr_t fifthOffset_Coordinates = *(uintptr_t*)(fourthOffset_Coordinates + 0x260);
            uintptr_t sixthOffset_Coordinates = *(uintptr_t*)(fifthOffset_Coordinates + 0x48);


            uintptr_t listAddress_Health = *(uintptr_t*)(baseAddress + 0x050A0B10);
            uintptr_t firstOffset_Health = *(uintptr_t*)(listAddress_Health + 0x8); //0x8, 0x448, 188, a8, 70, 448, 8, 88
            uintptr_t secondOffset_Health = *(uintptr_t*)(firstOffset_Health + 0xA8); //0x20, 0x2C8, 8, c8, 28, cc8, 30, ca8
            uintptr_t thirdOffset_Health = *(uintptr_t*)(secondOffset_Health + 0x18); //0x30, 0x48, 48, a0, c0, 48

            uintptr_t listAddress_Resources = *(uintptr_t*)(baseAddress + 0x050A0B10);
            uintptr_t firstOffset_Resources = *(uintptr_t*)(listAddress_Resources + 0x8); //0x8, 0x448, 188, a8, 70, 448, 8, 88
            uintptr_t secondOffset_Resources = *(uintptr_t*)(firstOffset_Resources + 0xA8); //0x20, 0x2C8, 8, c8, 28, cc8, 30, ca8
            uintptr_t thirdOffset_Resources = *(uintptr_t*)(secondOffset_Resources + 0x18); //0x30, 0x48, 48, a0, c0, 48, a0, 618

            uintptr_t listAddress_Movement = *(uintptr_t*)(baseAddress + 0x050A0B10);
            uintptr_t firstOffset_Movement = *(uintptr_t*)(listAddress_Movement + 0x8);
            uintptr_t secondOffset_Movement = *(uintptr_t*)(firstOffset_Movement + 0xA8);
            uintptr_t thirdOffset_Movement = *(uintptr_t*)(secondOffset_Movement + 0x18);

            for (unsigned int j = 0x0000; j <= 0xFFFF && counter < 5; j += 0x0008) { // Middle offset that denotes which character the information is about!
                Players character;
                getCoordinates(baseAddress, character, sixthOffset_Coordinates, counter);
                getHealth(baseAddress, character, thirdOffset_Health, j);
                getResources(baseAddress, character, thirdOffset_Resources, j);
                getMovement(baseAddress, character, thirdOffset_Movement, j);
                entity.addPlayers(character);
                counter++;
            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
    }

    void getEnemies(uintptr_t baseAddress) {
        __try {
            uintptr_t listAddress_Coordinates = *(uintptr_t*)(baseAddress + 0x04ED8DE8); //04EB39C0 or 04FBC278 or 04FBC160 or 04EA6480 or 04FBC278, 04EABC58, 04F02050
            uintptr_t firstOffset_Coordinates = *(uintptr_t*)(listAddress_Coordinates + 0x3C8); //0x8, 0x448, 188, a8, 70, 448, 8, 88
            for (unsigned int j = 0x0038; j <= 0xFFFF; j += 0x0008) {
                __try {
                    uintptr_t secondOffset_Coordinates = *(uintptr_t*)(firstOffset_Coordinates + j);

                    Enemies enemyChar;

                    //uintptr_t fifthOffset_Coordinates = *(uintptr_t*)(fourthOffset_Coordinates + 0x20); //0x68, 0x20, 20, 110, 0, 20, 110, 110
                    //uintptr_t sixthOffset_Coordinates = *(uintptr_t*)(fourthOffset_Coordinates + 0xE0); //0xE0, 0xE0 , E0, 148, b48, e0, 148, 148
                    //float* seventhOffset_Coordinates = (float*)(sixthOffset_Coordinates + 0x48); //0x48
                    //float* seventhOffset_Coordinates_other = (float*)(fourthOffset_Coordinates + 0x50); //for y coordinate

                    uintptr_t thirdOffset_Coordinates = *(uintptr_t*)(secondOffset_Coordinates + 0x20);
                    uintptr_t fourthOffset_Coordinates = *(uintptr_t*)(thirdOffset_Coordinates + 0xE0);
                    float* fifthOffset_Coordinates_x = (float*)(fourthOffset_Coordinates + 0x48);
                    float* fifthOffset_Coordinates_z = (float*)(fourthOffset_Coordinates + 0x4C);
                    float* fifthOffset_Coordinates_y = (float*)(fourthOffset_Coordinates + 0x50);

                    float x_Coordinate = *fifthOffset_Coordinates_x;
                    float z_Coordinate = *fifthOffset_Coordinates_z;
                    float y_Coordinate = *fifthOffset_Coordinates_y;

                    if (x_Coordinate < 9000 && x_Coordinate > -9000 &&
                        z_Coordinate < 100 && z_Coordinate > -100 &&
                        y_Coordinate < 9000 && y_Coordinate > -9000 &&
                        round(x_Coordinate) != 0 && round(x_Coordinate) != -0 &&
                        round(y_Coordinate) != 0 && round(y_Coordinate) != -0)
                    {
                        enemyChar.setCoordinates(x_Coordinate, z_Coordinate, y_Coordinate);
                        entity.addEnemies(enemyChar);
                    }
                }
                __except (EXCEPTION_EXECUTE_HANDLER) {}
            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}


    }

    void getCoordinatesCurrent(uintptr_t baseAddress, Players& character) {
        __try {
            uintptr_t listAddress_CurrentPlayer = *(uintptr_t*)(baseAddress + 0x04FECE48);
            uintptr_t firstOffset_CurrentPlayer = *(uintptr_t*)(listAddress_CurrentPlayer + 0x280);
            uintptr_t secondOffset_CurrentPlayer = *(uintptr_t*)(firstOffset_CurrentPlayer + 0x178);
            uintptr_t thirdOffset_CurrentPlayer = *(uintptr_t*)(secondOffset_CurrentPlayer + 0x378);
            uintptr_t fourthOffset_CurrentPlayer = *(uintptr_t*)(thirdOffset_CurrentPlayer + 0x88);
            uintptr_t fifthOffset_CurrentPlayer = *(uintptr_t*)(fourthOffset_CurrentPlayer + 0x68);
            uintptr_t sixthOffset_CurrentPlayer = *(uintptr_t*)(fifthOffset_CurrentPlayer + 0xE0);
            float* fifthOffset_CurrentPlayer_x = (float*)(sixthOffset_CurrentPlayer + 0x48);
            float* fifthOffset_CurrentPlayer_z = (float*)(sixthOffset_CurrentPlayer + 0x4C);
            float* fifthOffset_CurrentPlayer_y = (float*)(sixthOffset_CurrentPlayer + 0x50);

            float x_Coordinate = *fifthOffset_CurrentPlayer_x;
            float z_Coordinate = *fifthOffset_CurrentPlayer_z;
            float y_Coordinate = *fifthOffset_CurrentPlayer_y;
            character.setCoordinates(x_Coordinate, z_Coordinate, y_Coordinate);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
    }
    void getHealthCurrent(uintptr_t baseAddress, Players& character) {
        __try {
            uintptr_t listAddress_CurrentPlayer_Health = *(uintptr_t*)(baseAddress + 0x050A1908);
            uintptr_t firstOffset_CurrentPlayer_Health = *(uintptr_t*)(listAddress_CurrentPlayer_Health + 0x28);
            uintptr_t secondOffset_CurrentPlayer_Health = *(uintptr_t*)(firstOffset_CurrentPlayer_Health + 0x68);
            uintptr_t thirdOffset_CurrentPlayer_Health = *(uintptr_t*)(secondOffset_CurrentPlayer_Health + 0x50);
            uintptr_t fourthOffset_CurrentPlayer_Health = *(uintptr_t*)(thirdOffset_CurrentPlayer_Health + 0xC0);
            double* seventhOffset_CurrentPlayer_Health = (double*)(fourthOffset_CurrentPlayer_Health + 0x78);
            double* seventhOffset_CurrentPlayer_HealthMax = (double*)(fourthOffset_CurrentPlayer_Health + 0x88);
            double health = *seventhOffset_CurrentPlayer_Health;
            double maxHealth = *seventhOffset_CurrentPlayer_HealthMax;
            character.setHealth(health);
            character.setMaxHealth(maxHealth);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
    }
    void getResourcesCurrent(uintptr_t baseAddress, Players& character) {
        __try {
            uintptr_t listAddress_CurrentPlayer_Resources = *(uintptr_t*)(baseAddress + 0x050A4B20);
            uintptr_t firstOffset_CurrentPlayer_Resources = *(uintptr_t*)(listAddress_CurrentPlayer_Resources + 0x50);
            uintptr_t secondOffset_CurrentPlayer_Resources = *(uintptr_t*)(firstOffset_CurrentPlayer_Resources + 0x2C0);
            uintptr_t thirdOffset_CurrentPlayer_Resources = *(uintptr_t*)(secondOffset_CurrentPlayer_Resources + 0xD0);
            uintptr_t fourthOffset_CurrentPlayer_Resources = *(uintptr_t*)(thirdOffset_CurrentPlayer_Resources + 0x90);
            uintptr_t fifthOffset_CurrentPlayer_Resources = *(uintptr_t*)(fourthOffset_CurrentPlayer_Resources + 0xE0);
            uintptr_t sixthOffset_CurrentPlayer_Resources = *(uintptr_t*)(fifthOffset_CurrentPlayer_Resources + 0x2A8);
            uintptr_t seventhOffset_CurrentPlayer_Resources = *(uintptr_t*)(sixthOffset_CurrentPlayer_Resources + 0x18);

            for (unsigned int k = 0x0000; k <= 0x0030; k += 0x0008) {
                __try {
                    uintptr_t eighthOffset_CurrentPlayer_Resources = *(uintptr_t*)(seventhOffset_CurrentPlayer_Resources + k);
                    double* ninthOffset_CurrentPlayer_Resources = (double*)(eighthOffset_CurrentPlayer_Resources + 0x50);
                    char* ninthOffset_CurrentPlayer_Resources_Name = (char*)eighthOffset_CurrentPlayer_Resources + 0x120; // Gets the name of the resource
                    double resource = *ninthOffset_CurrentPlayer_Resources;

                    if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "ActionPoint") == 0) character.setAP(resource);
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "BonusActionPoint") == 0) {
                        character.setBP(resource);
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "ReactionActionPoint") == 0) {
                        character.setRP(resource);
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "BardicInspiration") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(2);
                        else character.setSecondClass(2);
                        character.setBardInsp(resource);
                        //if (character.getClassValue("Bard") == false) character.setClass("Bard");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "Rage") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(1);
                        else character.setSecondClass(1);
                        character.setRage(resource);
                        // if (character.getClassValue("Barbarian") == false) character.setClass("Barbarian");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "WildShape") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(4);
                        else character.setSecondClass(4);
                        character.setWildShape(resource);
                        // if (character.getClassValue("Druid") == false) character.setClass("Druid");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "SneakAttack_Charge") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(9);
                        else character.setSecondClass(9);
                        character.setSneakAttack(resource); // check again for the name
                        // if (character.getClassValue("Rogue") == false) character.setClass("Rogue");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "KiPoint") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(6);
                        else character.setSecondClass(6);
                        character.setKiP(resource);
                        //  if (character.getClassValue("Monk") == false) character.setClass("Monk");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "ChannelDivinity") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(3);
                        else character.setSecondClass(3);
                        character.setChannelDivinity(resource);
                        // if (character.getClassValue("Cleric") == false) character.setClass("Cleric");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "TidesOfChaos") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(10);
                        else character.setSecondClass(10);
                        character.setChaos(resource);
                        //if (character.getClassValue("Sorcerer") == false) character.setClass("Sorcerer");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "SorceryPoint") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(10);
                        else character.setSecondClass(10);
                        character.setSorcPoint(resource);
                        //if (character.getClassValue("Sorcerer") == false) character.setClass("Sorcerer");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "ArcaneRecoveryPoint") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(12);
                        else character.setSecondClass(12);
                        character.setArcaneP(resource);
                        // if (character.getClassValue("Wizard") == false) character.setClass("Wizard");
                    }
                    else if (strcmp(ninthOffset_CurrentPlayer_Resources_Name, "ChannelOathCharge") == 0) {
                        if (character.getFirstClass() == 0) character.setFirstClass(7);
                        else character.setSecondClass(7);
                        character.setOath(resource);
                        //  if (character.getClassValue("Paladin") == false) character.setClass("Paladin");
                    }
                }
                __except (EXCEPTION_EXECUTE_HANDLER) {}
            }
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
    }
    void getMovementCurrent(uintptr_t baseAddress, Players& character) {
        __try {
            uintptr_t listAddress_CurrentPlayer_Movement = *(uintptr_t*)(baseAddress + 0x050A4B20);
            uintptr_t firstOffset_CurrentPlayer_Movement = *(uintptr_t*)(listAddress_CurrentPlayer_Movement + 0x50);
            uintptr_t secondOffset_CurrentPlayer_Movement = *(uintptr_t*)(firstOffset_CurrentPlayer_Movement + 0x148);
            uintptr_t thirdOffset_CurrentPlayer_Movement = *(uintptr_t*)(secondOffset_CurrentPlayer_Movement + 0xD8);
            uintptr_t fourthOffset_CurrentPlayer_Movement = *(uintptr_t*)(thirdOffset_CurrentPlayer_Movement + 0x50);
            uintptr_t fifthOffset_CurrentPlayer_Movement = *(uintptr_t*)(fourthOffset_CurrentPlayer_Movement + 0x38);
            uintptr_t sixthOffset_CurrentPlayer_Movement = *(uintptr_t*)(fifthOffset_CurrentPlayer_Movement + 0x48);
            double* seventhOffset_CurrentPlayer_Movement = (double*)(sixthOffset_CurrentPlayer_Movement + 0x50);
            double movement = *seventhOffset_CurrentPlayer_Movement;
            character.setMovement(movement);
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
    }
    void getCurrentCharacter(uintptr_t baseAddress) {
        Players currPlayer;
        getCoordinatesCurrent(baseAddress, currPlayer);
        getHealthCurrent(baseAddress, currPlayer);
        getResourcesCurrent(baseAddress, currPlayer);
        getMovementCurrent(baseAddress, currPlayer);
        entity.addPlayers(currPlayer);

    }
    void getCurrentPlayerCoordinates(float& x_Current, float& z_Current, float& y_Current) {
        x_Current = round(entity.getPlayers()[0].getXCoord());
        z_Current = round(entity.getPlayers()[0].getZCoord());
        y_Current = round(entity.getPlayers()[0].getYCoord());
    }

    void getEntities(uintptr_t baseAddress) {
        entity.clearVectors();
        getCurrentCharacter(baseAddress);
        getParty(1, baseAddress);
        getEnemies(baseAddress);
    }
    Entity retEntity() {
        return entity;
    }

    void moveCamera(uintptr_t baseAddress, float x_Target, float z_Target, float y_Target, Entity entity) {
        // Get the cursor, get the camera coordinates
        float x_Cursor, z_Cursor, y_Cursor;
        float x_Camera, z_Camera, y_Camera, posX_Camera, posY_Camera;
        controller.getCursor(baseAddress, x_Cursor, z_Cursor, y_Cursor);
        controller.getCamera(baseAddress, x_Camera, z_Camera, y_Camera, posX_Camera, posY_Camera);

        // Check if camera is positioned right
        // while (round(posX_Camera) != 0 && round(posY_Camera) != 0){
        // }

        // Move mouse to the center
        controller.moveMouse(midX, midY);
    loop:
        do {
            // If you want to manually stop the camera from moving
            if (GetAsyncKeyState(VK_F6) & 1) {
                printf("Stop camera movement! \n");
                break;
            }

            controller.getCursor(baseAddress, x_Cursor, z_Cursor, y_Cursor); // Update the cursor's coordinates
            controller.getCamera(baseAddress, x_Camera, z_Camera, y_Camera, posX_Camera, posY_Camera);
            //if (controller.isCursorOnNPC(baseAddress) == 1)cout << "Cursor is on NPC" << endl;
            //else cout << "Cursor is not on NPC" << endl;
            //if (controller.isCursorOnNPC(baseAddress) == 1 && round(x_Cursor) == round(x_Target)) break; // If cursor is pointing at the right coordinates, stop
            if (round(x_Cursor) == round(x_Target) && round(z_Cursor) == round(z_Target) && round(y_Cursor) == round(y_Target)) break;

            // Using a 2D coordinate plane, in order to check in which direction the camera should go
            
            // If x is positive
            if (x_Cursor > 0) {
                // If y is positive
                if (y_Cursor > 0) {
                    if (x_Cursor < x_Target) {
                        if (y_Cursor < y_Target) {
                            controller.moveCamRightUp();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamRightDown();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamRight();
                            goto loop;
                        }
                    }

                    else if (x_Cursor > x_Target) {

                        if (y_Cursor < y_Target) {
                            controller.moveCamLeftUp();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamLeftDown();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamLeft();
                            goto loop;
                        }
                    }

                    else {
                        if (y_Cursor < y_Target) {
                            controller.moveCamUp();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamDown();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            printf("You're already there then \n");
                            goto loop;
                        }
                    }
                }
                // If y is negative
                else {
                    if (x_Cursor < x_Target) {
                        if (y_Cursor < y_Target) {
                            controller.moveCamRightDown();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamRightUp();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamRight();
                            goto loop;
                        }
                    }

                    else if (x_Cursor > x_Target) {

                        if (y_Cursor < y_Target) {
                            controller.moveCamLeftDown();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamLeftUp();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamLeft();
                            goto loop;
                        }
                    }

                    else {
                        if (y_Cursor < y_Target) {
                            controller.moveCamDown();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamUp();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            printf("You're already there then \n");
                            goto loop;
                        }
                    }
                }
            }

            // If x is negative
            else if (x_Cursor < 0) {
                // If y is positive
                if (y_Cursor > 0) {
                    if (x_Cursor < x_Target) {
                        if (y_Cursor < y_Target) {
                            controller.moveCamLeftUp();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamLeftDown();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamLeft();
                            goto loop;
                        }
                    }

                    else if (x_Cursor > x_Target) {

                        if (y_Cursor < y_Target) {
                            controller.moveCamRightUp();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamRightDown();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamRight();
                            goto loop;
                        }
                    }

                    else {
                        if (y_Cursor < y_Target) {
                            controller.moveCamUp();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamDown();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            printf("You're already there then \n");
                            goto loop;
                        }
                    }
                }
                // If y is negative
                else {
                    if (x_Cursor < x_Target) {
                        if (y_Cursor < y_Target) {
                            controller.moveCamLeftDown();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamLeftUp();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamLeft();
                            goto loop;
                        }
                    }

                    else if (x_Cursor > x_Target) {

                        if (y_Cursor < y_Target) {
                            controller.moveCamRightDown();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamRightUp();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            controller.moveCamRight();
                            goto loop;
                        }
                    }

                    else {
                        if (y_Cursor < y_Target) {
                            controller.moveCamDown();
                            goto loop;
                        }
                        else if (y_Cursor > y_Target) {
                            controller.moveCamUp();
                            goto loop;
                        }
                        else if (y_Cursor == y_Target) {
                            goto loop;
                        }
                    }
                }
            }
        } while ((round(x_Cursor) == round(x_Target) && round(z_Cursor) == round(z_Target) && round(y_Cursor) == round(y_Target)));
        controller.moveMouse(midX, midY);
    }
    void runAway(Players player, Enemies enemy, Entity entity, uintptr_t baseAddress){
        float x = player.getXCoord() - enemy.getXCoord();
        float y = player.getYCoord() - enemy.getYCoord();
        float newX = x * 2;
        float newY = y * 2;
        moveCamera(baseAddress, newX, 0, newY, entity);
        controller.clickMouse(midX, midY);
    }

    void Run(uintptr_t baseAddress) {
    getEntity:
        Sleep(1000);
        if (GetAsyncKeyState(VK_F7) & 1) return;
        getEntities(baseAddress);
        cout << "Checking what the current character should do ..." << endl;
        Players player = entity.getPlayers()[0];
        Enemies enemy;
        game.getClosestEnemy(player, enemy, entity);
        float distance = sqrt(pow(enemy.getXCoord() - player.getXCoord(), 2) + pow(enemy.getYCoord() - player.getYCoord(), 2));
        cout << "Distance is " << distance << endl;

    start:
        Sleep(600);
            if (game.isHealthLow(player)) {
                cout << "They should health themselves! They are in a critical state!" << endl;
                if (game.isAPEmpty(player)) {
                    cout << "However, they have no ation points. They cannot heal right now." << endl;
                    if (game.isMovementEmpty(player)) {
                        cout << "They don't have any movement left either, and so they can't run away. " << endl;
                        cout << "They should end their turn and hope for the best. " << endl;
                      controller.endTurn();
                        Sleep(1000);
                        goto getEntity;
                    }
                    else {
                        cout << "They have " << player.getMovement() << " movement!  They can use it to run away." << endl;
                        cout << "The closest enemy is at " << enemy.getXCoord() << " " << enemy.getZCoord() << " " << enemy.getYCoord() << ". They need to get away from that location!" << endl;
                        runAway(player, enemy, entity, baseAddress);
                        Sleep(300);
                        controller.endTurn();
                        Sleep(1000);
                        goto getEntity;
                    }
                }
                else {
                    cout << "They have some action points! They can use a healing potion, if they have one." << endl;
                    controller.useHealingItem();
                    goto start;
                }
            }
            else {
                if (game.isAPEmpty(player)) {
                    cout << "They're not in a critical state, but they've run out of action points. Can't really fight right now!" << endl;
                    cout << "They should end their turn" << endl;
                    controller.endTurn();
                    Sleep(1000);
                    goto getEntity;
                }
                else {
                    cout << "They're not in a critical state, and they have " << player.getAP() << " action points! They're in a good shape to fight. " << endl;
                    cout << "The closest enemy is at " << enemy.getXCoord() << " " << enemy.getZCoord() << " " << enemy.getYCoord() << ". They need to go to that location!" << endl;

                    Sleep(1000);
                    moveCamera(baseAddress, enemy.getXCoord(), enemy.getZCoord(), enemy.getYCoord(), entity);
                    controller.moveMouse(midX, midY);



                    if (distance > player.getMovement()) {
                        cout << "This enemy is out of reach.A ranged attack might be necessary!" << endl;
                        controller.rangeWeapon();
                        Sleep(600);
                        controller.keyHold(0xA2);
                        controller.clickMouse(midX, midY);
                        Sleep(600);
                        controller.keyRelease(0xA2);
                        Sleep(200);
                        goto start;
                    }
                    else {
                        cout << "This enemy is in reach. A melee attack is possible!" << endl;
                        controller.meleeWeapon();
                        Sleep(600);
                        controller.keyHold(0xA2);
                        controller.clickMouse(midX, midY);
                        Sleep(600);
                        controller.keyRelease(0xA2);
                        Sleep(200);
                        goto start;
                    }

                }
            }
       
    }
   
private:
    int const screen_Width = GetSystemMetrics(SM_CXSCREEN);
    int const screen_Height = GetSystemMetrics(SM_CYSCREEN);
    int const midX = screen_Width / 2;
    int const midY = screen_Height / 2;
    Entity entity;
    Controller controller;
    GameChecker game;
};