// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream> 
#include "Entity.cpp"
#include <cmath>
#include <dinput.h>
#include "Autoplayer.cpp"

using namespace std;


Entity entity;
Autoplayer autoplayer;
Controller controller;
GameChecker game;
int const screen_Width = GetSystemMetrics(SM_CXSCREEN);
int const screen_Height = GetSystemMetrics(SM_CYSCREEN);
int const midX = screen_Width / 2;
int const midY = screen_Height / 2;


DWORD WINAPI injectedCode(HMODULE hmodule) {

    AllocConsole();
    FILE* f = new FILE;
    freopen_s(&f, "CONOUT$", "w", stdout);

    cout << "Process ID is: " << GetCurrentProcessId() << endl;

    uintptr_t baseAddress = (uintptr_t)GetModuleHandle(0);
    HWND gameWindow = FindWindowA(NULL, "bg3_dx11.exe");
    if (baseAddress) printf("Base address of bg3_dx11.exe is: %p\n", baseAddress);

    while (true) {
        autoplayer.getEntities(baseAddress);
        entity = autoplayer.retEntity();
        game.setEntity(entity);

        if (GetAsyncKeyState(VK_F6) & 1) { // ALL WORKS !
            int count = 0;
            for (size_t i = 0; i < entity.getPlayers().size(); i++) {
                Players character = entity.getPlayers()[i];
                cout << "Player character number " << i << " has the following stats: " << endl;
                character.displayInformation();
            }
            for (size_t i = 0; i < entity.getEnemies().size(); i++) {
                Enemies character = entity.getEnemies()[i];
                cout << "Enemy characters coordinates for enemy number " << i << " x : " << character.getXCoord() << " z:  " << character.getZCoord() << " y: " << character.getYCoord() << endl;
            }
            autoplayer.Run(baseAddress);
        }

        if (GetAsyncKeyState(VK_F7) & 1) {
            autoplayer.getEntities(baseAddress);
            entity = autoplayer.retEntity();
            Players player = entity.getPlayers()[0];
            Enemies enemy;
            game.getClosestEnemy(player, enemy, entity);
            autoplayer.moveCamera(baseAddress, enemy.getXCoord(), enemy.getZCoord(), enemy.getYCoord(), entity);
        }

    }
    return 0;
}



// This is the main method that runs when the DLL is injected.
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)injectedCode, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
