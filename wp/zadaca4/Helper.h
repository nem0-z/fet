#pragma once

#include <windows.h>
#include "resources.h"
#include "Equation.h"

#define BUF_SIZE 10
#define CMD_DRAW 1000
#define PARSE_OK 2000

struct Helper{
    HWND equationList;
    char textBuffer[BUF_SIZE];
    int createControls(HWND);
    int parseInput(HWND);
};
