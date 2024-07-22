#pragma once
#include "pch.h"
#include "GameChecker.cpp"
#include <iostream> 
#include <string>

using namespace std;

class Controller {
public:
    GameChecker check;

    // Given 2 3d points, returns the delta between all 3 coordinates
    void direction(float x_Current, float z_Current, float y_Current, float x_Target, float z_Target, float y_Target, float& delta_X, float& delta_Z, float& delta_Y) {
        delta_X = x_Target - x_Current; // > 0 -> right, < 0 -> left
        delta_Z = z_Target - z_Current; // > 0 ->  above, < 0 -> below
        delta_Y = y_Target - y_Current; // > 0 -> up, < 0 -> down
    }
    // Used in the camera movement function to check if the cursor is at the target
    bool isAtTarget(float x_Current, float z_Current, float y_Current, float x_Target, float z_Target, float y_Target) {
        float delta_X, delta_Z, delta_Y;
        direction(x_Current, z_Current, y_Current, x_Target, z_Target, y_Target, delta_X, delta_Z, delta_Y);
        float distance = sqrt(pow(delta_X, 2) + pow(delta_Y, 2));
        return (distance <= 0.1);
    }

    // Mouse related controls
    void moveMouse(int x, int y) {
        POINT mouse;
        GetCursorPos(&mouse); // Get cursor
        // Normalising x and y to be suitable for mouse input
        double normalised_x = x * (65535 / (screen_Width - 1));
        double normalised_y = y * (65535 / (screen_Height - 1));

        INPUT Input;
        Input.type = INPUT_MOUSE;
        Input.mi.dx = (LONG)normalised_x;
        Input.mi.dy = (LONG)normalised_y;
        Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE; // Responsible for moving the mouse to the center
        SendInput(1, &Input, sizeof(INPUT));
    }
    void clickMouse(int x, int y) {
        POINT mouse;
        GetCursorPos(&mouse); // Get cursor 
        // Normalising x and y to be suitable for mouse input
        double normalised_x = x * (65535 / (screen_Width - 1));
        double normalised_y = y * (65535 / (screen_Height - 1));

        INPUT Input;
        Input.type = INPUT_MOUSE;
        Input.mi.dx = (LONG)normalised_x;
        Input.mi.dy = (LONG)normalised_y;
        Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE; // Responsible for moving the mouse; Move -> mouse movement; Absolute -> absolute coordinates
        SendInput(1, &Input, sizeof(INPUT));
        Sleep(100);
        Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN ; 
        // Responsible for making the mouse click; Move -> mouse movement; Absolute -> absolute coordinates; Leftdown -> press left button; Leftup -> lift left button
        SendInput(1, &Input, sizeof(INPUT));
        Sleep(100);
        Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &Input, sizeof(INPUT));
    }

    void moveUp() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX, midY - 55);
        printf("Move up \n");
    }
    void moveDown() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX, midY + 55);
        printf("Move down \n");
    }
    void moveLeft() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX - 55, midY);
        printf("Move Left \n");
    }
    void moveRight() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX + 55, midY);
        printf("Move right \n");
    }
    void moveDiagUpRight() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX + 50, midY - 50);
        printf("Move diagonally up right \n");
    }
    void moveDiagDownRight() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX + 50, midY + 50);
        printf("Move diagonally down right \n");
    }
    void moveDiagUpLeft() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX - 50, midY - 50);
        printf("Move diagonally up left \n");
    }
    void moveDiagDownLeft() {
        int screen_Width = GetSystemMetrics(SM_CXSCREEN);
        int screen_Height = GetSystemMetrics(SM_CYSCREEN);
        int midX = screen_Width / 2;
        int midY = screen_Height / 2;
        clickMouse(midX - 50, midY + 50);
        printf("Move diagonally down left \n");
    }

    // Cursor related functions
    void getCursor(uintptr_t baseAddress, float& cursor_X, float& cursor_Z, float& cursor_Y) {
        __try {
            uintptr_t listAddress_Cursor = *(uintptr_t*)(baseAddress + 0x04ED8DE8);
            uintptr_t firstOffset_Cursor = *(uintptr_t*)(listAddress_Cursor + 0x5C8);
            uintptr_t secondOffset_Cursor = *(uintptr_t*)(firstOffset_Cursor + 0x88);
            uintptr_t thirdOffset_Cursor = *(uintptr_t*)(secondOffset_Cursor + 0xA0);
            uintptr_t fourthOffset_Cursor = *(uintptr_t*)(thirdOffset_Cursor + 0x18);
            uintptr_t fifthOffset_Cursor = *(uintptr_t*)(fourthOffset_Cursor + 0x8);
            uintptr_t sixthOffset_Cursor = *(uintptr_t*)(fifthOffset_Cursor + 0x10);
            uintptr_t seventhOffset_Cursor = *(uintptr_t*)(sixthOffset_Cursor + 0x1E8);
            uintptr_t eighthOffset_Cursor = *(uintptr_t*)(seventhOffset_Cursor + 0x50);
            float* ninthOffset_Cursor_x = (float*)(eighthOffset_Cursor + 0x0);
            float* ninthOffset_Cursor_z = (float*)(eighthOffset_Cursor + 0x4);
            float* ninthOffset_Cursor_y = (float*)(eighthOffset_Cursor + 0x8);

            cursor_X = *ninthOffset_Cursor_x;
            cursor_Z = *ninthOffset_Cursor_z;
            cursor_Y = *ninthOffset_Cursor_y;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
    }
    bool isCursorOnNPC(uintptr_t baseAddress) {
        int isCursorOnNPC = -1;
        __try {
            uintptr_t listAddress_Cursor = *(uintptr_t*)(baseAddress + 0x04E373B0);
            uintptr_t firstOffset_Cursor = *(uintptr_t*)(listAddress_Cursor + 0x60);
            uintptr_t secondOffset_Cursor = *(uintptr_t*)(firstOffset_Cursor + 0x138);
            uintptr_t thirdOffset_Cursor = *(uintptr_t*)(secondOffset_Cursor + 0x88);
            uintptr_t fourthOffset_Cursor = *(uintptr_t*)(thirdOffset_Cursor + 0x30);
            uintptr_t fifthOffset_Cursor = *(uintptr_t*)(fourthOffset_Cursor + 0x38);
            uintptr_t sixthOffset_Cursor = *(uintptr_t*)(fifthOffset_Cursor + 0x0);
            uintptr_t seventhOffset_Cursor = *(uintptr_t*)(sixthOffset_Cursor + 0x10);
            uintptr_t eighthOffset_Cursor = *(uintptr_t*)(seventhOffset_Cursor + 0x0);
            uintptr_t ninthOffset_Cursor = *(uintptr_t*)(eighthOffset_Cursor + 0x80);
            uintptr_t tenhthOffset_Cursor = *(uintptr_t*)(ninthOffset_Cursor + 0x0);
            uintptr_t eleventhOffset_Cursor = *(uintptr_t*)(tenhthOffset_Cursor + 0x100);
            int* twelfthhOffset_Cursor = (int*)(eleventhOffset_Cursor + 54);

            isCursorOnNPC = *twelfthhOffset_Cursor;
        }
        __except (EXCEPTION_EXECUTE_HANDLER) {}
        return isCursorOnNPC; // 1 if yes, 0 if no, -1 if no
    }
    void printCursorCoords() {
        POINT mouse;
        GetCursorPos(&mouse);
        cout << "Cursor position x: " << mouse.x << " and y: " << mouse.y << endl;
    }

    void getDistFromCursor(uintptr_t baseAddress, float& distFromCursor) {
            __try {
                uintptr_t listAddress_CurrentPlayer_Dist = *(uintptr_t*)(baseAddress + 0x04E9E6F8);
                uintptr_t firstOffset_CurrentPlayer_Dist = *(uintptr_t*)(listAddress_CurrentPlayer_Dist + 0x98);
                uintptr_t secondOffset_CurrentPlayer_Dist = *(uintptr_t*)(firstOffset_CurrentPlayer_Dist + 0x98);
                uintptr_t thirdOffset_CurrentPlayer_Dist = *(uintptr_t*)(secondOffset_CurrentPlayer_Dist + 0x60);
                uintptr_t fourthOffset_CurrentPlayer_Dist = *(uintptr_t*)(thirdOffset_CurrentPlayer_Dist + 0x400);
                uintptr_t fifthOffset_CurrentPlayer_Dist = *(uintptr_t*)(fourthOffset_CurrentPlayer_Dist + 0x6B8);
                uintptr_t sixthOffset_CurrentPlayer_Dist = *(uintptr_t*)(fifthOffset_CurrentPlayer_Dist + 0x80);
                uintptr_t seventhOffset_CurrentPlayer_Dist = *(uintptr_t*)(sixthOffset_CurrentPlayer_Dist + 0x18);
                uintptr_t eighthOffset_CurrentPlayer_Dist = *(uintptr_t*)(seventhOffset_CurrentPlayer_Dist + 0x150);
                uintptr_t ninthOffset_CurrentPlayer_Dist = *(uintptr_t*)(eighthOffset_CurrentPlayer_Dist + 0x90);
                //uintptr_t tenthOffset_CurrentPlayer_Dist = *(uintptr_t*)(ninthOffset_CurrentPlayer_Dist + 0x90);

                float* eleventhOffset_CurrentPlayer_Dist = (float*)(ninthOffset_CurrentPlayer_Dist + 0x78);
                distFromCursor = *eleventhOffset_CurrentPlayer_Dist;
                cout << "Distance from cursor is " << distFromCursor << endl;
            }
            __except (EXCEPTION_EXECUTE_HANDLER) { cout << "Error error" << endl; }
        }

    // Keyboard related controls
    void pressKey(WORD key) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.time = 0; // No timestamp
        input.ki.wVk = 0; // Virtual key code 
        input.ki.dwExtraInfo = 0;
        input.ki.dwFlags = KEYEVENTF_SCANCODE; // Flag to specify it's for a scan
        input.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC); // Maps a virtual key code into a scan code/character value. ESSENTIAL! 
        SendInput(1, &input, sizeof(INPUT));
        Sleep(50); // Wait 500 miliseconds
        input.ki.dwFlags = KEYEVENTF_KEYUP; // Flag to release the key
        SendInput(1, &input, sizeof(INPUT)); // Resend the input
        Sleep(100);
    }
    void pressTwoKeys(WORD key1, WORD key2) {
        INPUT input[2] = { 0 };
        input[0].type = INPUT_KEYBOARD;
        input[0].ki.time = 0;
        input[0].ki.wVk = 0; // Virtual key code 
        input[0].ki.dwFlags = KEYEVENTF_SCANCODE;
        input[0].ki.wScan = MapVirtualKey(key1, MAPVK_VK_TO_VSC);
        input[1].type = INPUT_KEYBOARD;
        input[1].ki.time = 0;
        input[1].ki.wVk = 0; // Virtual key code 
        input[1].ki.dwFlags = KEYEVENTF_SCANCODE;
        input[1].ki.wScan = MapVirtualKey(key2, MAPVK_VK_TO_VSC);
        SendInput(2, input, sizeof(INPUT));
        Sleep(50);
        input[0].ki.dwFlags = KEYEVENTF_KEYUP; // Flag to release the key
        input[1].ki.dwFlags = KEYEVENTF_KEYUP; // Flag to release the key
        SendInput(2, input, sizeof(INPUT));
        Sleep(100);
    }

    void keyHold(WORD key) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.time = 0;
        input.ki.wVk = 0;
        input.ki.dwExtraInfo = 0;
        input.ki.dwFlags = KEYEVENTF_SCANCODE;
        input.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
        SendInput(1, &input, sizeof(INPUT));
        Sleep(100);
    }
    void keyRelease(WORD key) {
        INPUT input;
        input.type = INPUT_KEYBOARD;
        input.ki.time = 0;
        input.ki.wVk = 0;
        input.ki.dwExtraInfo = 0;
        input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
        input.ki.wScan = MapVirtualKey(key, MAPVK_VK_TO_VSC);
        SendInput(1, &input, sizeof(INPUT));
        Sleep(100);
    }

    // Camera manipulation
    void getCamera(uintptr_t baseAddress, float& camera_X, float& camera_Z, float& camera_Y, float& camera_posX, float& camera_posY) {
        uintptr_t listAddress_Camera = *(uintptr_t*)(baseAddress + 0x04ED2CC0);
        uintptr_t firstOffset_Camera = *(uintptr_t*)(listAddress_Camera + 0x8);
        uintptr_t secondOffset_Camera = *(uintptr_t*)(firstOffset_Camera + 0xB8);
        uintptr_t thirdOffset_Camera = *(uintptr_t*)(secondOffset_Camera + 0x1A8);
        uintptr_t fourthOffset_Camera = *(uintptr_t*)(thirdOffset_Camera + 0x170);
        float* fifthOffset_Camera_x = (float*)(fourthOffset_Camera + 0x4C);
        float* fifthOffset_Camera_z = (float*)(fourthOffset_Camera + 0x50);
        float* fifthOffset_Camera_y = (float*)(fourthOffset_Camera + 0x54);
        float* fifthOffset_Camera_PositioningX = (float*)(fourthOffset_Camera + 0x58);
        float* fifthOffset_Camera_PositioningY = (float*)(fourthOffset_Camera + 0X60);

        camera_X = *fifthOffset_Camera_x;
        camera_Z = *fifthOffset_Camera_z;
        camera_Y = *fifthOffset_Camera_y;
        camera_posX = *fifthOffset_Camera_PositioningX; // Must be 0.049375 or smth  
        camera_posY = *fifthOffset_Camera_PositioningY; // MUST BE 0.84922
        // Simulate q and e until you get to those positions
        // Use coordinates to simulate WSAD
        // To center on enemy -> go baby steps towards the enemy, so that they're at the center of the screen
        // Then, when they're at the center, click on weapon and then back on them! Aaaand boom you attack them without doing a million baby steps

    }
    void moveCamLeft() {
        pressKey(0x41); // press A
    }
    void moveCamRight() {
        pressKey(0x44);
    }
    void moveCamUp() {
        pressKey(0x57);
    }
    void moveCamDown() {
        pressKey(0x53);
    }
    void moveCamLeftUp() {
        pressTwoKeys(0x41, 0x57);
    }
    void moveCamLeftDown() {
        pressTwoKeys(0x41, 0x53);
    }
    void moveCamRightUp() {
        pressTwoKeys(0x44, 0x57);
    }
    void moveCamRightDown() {
        pressTwoKeys(0x44, 0x53);
    }
    void rotateCameraLeft() {
        pressKey(0x51);
    }
    void rotateCameraRight() {
        pressKey(0x44);
    }

    // Attack: x: 843, y: 1017, left ctrl hold
    // Jump: Z, Hide: C, Throw: X + choose item : x: 972, y: 1057
    // Dash: x: 789, y: 951
    // Disengage: x: 839, y: 958
    // Dip: x: 651, y: 1003
    // Shove: x: 701, y: 1007
    // Improvised meele weapon: x: 750, y: 994 (try 1007)
    // Weapon 1: x: 525, y: 991
    // Weapon 2: x: 585, y: 991
    // Distance between middle of two abilities/buttons: x: 47-ish, y: 50-ish
    // toggle weapon set: F
    // toggle dual wielding: R
    // sheathe weapon: U
    // End/cancel turn: space
    // Short rest: Y
    // Flee from combat: shift + space
    // Select next character: Right bracket ]
    // Select previous character: Left bracket [
    // slot 1: 1
    // health potion: 1315 962, 1311 993, 1360 955 OR 1358 997

    // In-game actions
    void jump(int x, int y) {
        pressKey(0x5A);
        clickMouse(x, y);
    }
    void hide() {
        pressKey(0x43);
    }
    void dash() {
        clickMouse(789, 951);
        Sleep(100);
    }
    void disengage() {
        clickMouse(839, 958);
        Sleep(50);
    }
    void dip(int x, int y) {
        clickMouse(651, 1003);
        Sleep(50);
        clickMouse(x, y);
    }
    void shove(int x, int y) {
        clickMouse(701, 1007);
        Sleep(50);
        clickMouse(x, y);
    }
    void switchWeapons() {
        pressKey(0x46);
    }
    void endTurn() {
        pressKey(0x20);
    }
    void shortRest() {
        pressKey(0x59);
    }
    void flee() {
        pressTwoKeys(0xA0, 0x20);
    }
    void selectNextChar() {
        pressKey(0xDD);
    }
    void selectPreviousChar() {
        pressKey(0xDB);
    }
    void focusOnFirstChar() {
        pressKey(0x70);
    }
    void focusOnSecondChar() {
        pressKey(0x71);
    }
    void focusOnThirdChar() {
        pressKey(0x72);
    }
    void focusOnFourthChar() {
        pressKey(0x73);
    }
    void useHealingItem() {
        clickMouse(1315, 962); // Assume healing potion is in the first slot
    }
    void meleeWeapon() {
        clickMouse(530, 1000);
    }
    void rangeWeapon() {
        clickMouse(584, 1000);
    }

private:
    int const screen_Width = GetSystemMetrics(SM_CXSCREEN);
    int const screen_Height = GetSystemMetrics(SM_CYSCREEN);
    int const midX = screen_Width / 2;
    int const midY = screen_Height / 2;
};

