#pragma once

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <list>

#ifndef PRESSED
#define PRESSED(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#endif

enum Direction {
    LEFT,
    RIGHT
};

typedef struct ObjectInfo {
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;

    int dx = 0;
    int dy = 0;

    int direction = LEFT;

    int counter_left_x = 0;
    int counter_right_x = 8;
    int counter_y = 0;
} Object;

const int WOMAN_DX = 5, BIKE_DX = 6, BIKE_DY = 2;

extern Object woman, bike;
extern HBITMAP hbm_city,
            hbm_woman, hbm_woman_right, hbm_woman_black, hbm_woman_right_black,
            hbm_bike, hbm_bike_right, hbm_bike_black, hbm_bike_right_black;
extern BITMAP bm_woman, bm_city, bm_bike;
extern RECT rect;
extern std::list<Object> bikes;

void initialize_object(Object *object, const BITMAP *bm);
void load_bitmaps();
void initialize(HWND hwnd);
void check_input();
void update_counter(Object *object);
void update_object(Object *object);
void update(HWND hwnd);
void draw(HDC hdc);
void render(HWND hwnd);
void add_new_bike();
