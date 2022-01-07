#include "my_header.hpp"

Object woman, bike;
HBITMAP hbm_city,
            hbm_woman, hbm_woman_right, hbm_woman_black, hbm_woman_right_black,
            hbm_bike, hbm_bike_right, hbm_bike_black, hbm_bike_right_black;
BITMAP bm_woman, bm_city, bm_bike;
RECT rect;
std::list<Object> bikes;

void initialize_object(Object *object, const BITMAP *bm) {
    object->width = bm->bmWidth / 8;
    object->height = bm->bmHeight / 3;
    object->x = rect.right;
    object->y = rect.bottom - object->height;
}

void load_bitmaps() {
    hbm_city = (HBITMAP) LoadImage(NULL, "city.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_woman = (HBITMAP) LoadImage(NULL, "woman.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_woman_right = (HBITMAP) LoadImage(NULL, "woman_right.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_woman_black = (HBITMAP) LoadImage(NULL, "woman_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_woman_right_black = (HBITMAP) LoadImage(NULL, "woman_right_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    hbm_bike = (HBITMAP) LoadImage(NULL, "bike.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_bike_right = (HBITMAP) LoadImage(NULL, "bike_right.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_bike_black = (HBITMAP) LoadImage(NULL, "bike_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_bike_right_black = (HBITMAP) LoadImage(NULL, "bike_right_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

void initialize(HWND hwnd) {
    GetClientRect(hwnd, &rect);

    load_bitmaps();

    GetObject(hbm_woman, sizeof(BITMAP), &bm_woman);
    GetObject(hbm_city, sizeof(BITMAP), &bm_city);
    GetObject(hbm_bike, sizeof(BITMAP), &bm_bike);

    initialize_object(&woman, &bm_woman);
    initialize_object(&bike, &bm_bike);

    woman.dx = -WOMAN_DX;
    bike.dx = -BIKE_DX;
}

void check_input() {
    if (PRESSED(VK_LEFT)) {
        woman.dx = -WOMAN_DX;
        woman.direction = LEFT;
    } else if (PRESSED(VK_RIGHT)) {
        woman.dx = WOMAN_DX;
        woman.direction = RIGHT;
    } else if (PRESSED(0x41)) { //A key
        bike.dx = -BIKE_DX;
        bike.direction = LEFT;
    } else if (PRESSED(0x44)) { //D key
        bike.dx = BIKE_DX;
        bike.direction = RIGHT;
    } else if (PRESSED(0x57)) { //W key
        if (bike.y > rect.bottom - bike.height - 10)
            bike.y -= BIKE_DY;
    } else if (PRESSED(0x53)) { //S key
        if (bike.y < rect.bottom - bike.height + 30)
            bike.y += BIKE_DY;
    }
}

void update_counter(Object *object) {
    if (object->direction == LEFT){
       object->counter_left_x++;
        if (object->counter_left_x == 8) {
            object->counter_left_x = 0;
            object->counter_y++;
        }
    } else if (object->direction == RIGHT) {
        object->counter_right_x--;
        if (object->counter_right_x == 0) {
            object->counter_right_x = 7;
            object->counter_y++;
        }
    }

    if (object->counter_y > 2) {
        object->counter_y = 0;
    }
}

void update_object(Object *object) {
    object->x += object->dx;

    if (object->direction == LEFT && object->x < -object->width) {
        object->x = rect.right;
    }

    if (object->direction == RIGHT && object->x > rect.right) {
        object->x = -object->width;
    }

    update_counter(object);
}

void update(HWND hwnd) {
    GetClientRect(hwnd, &rect);
    update_object(&woman);
    update_object(&bike);

    for (auto &bike: bikes) {
        bike.x += bike.dx;
        update_counter(&bike);
    }

    if (!bikes.empty() && bikes.front().x < -bikes.front().width) {
        bikes.pop_front();
    }
}

void draw(HDC hdc) {
    HDC hdc_buffer = CreateCompatibleDC(hdc);
    HBITMAP hbm_buffer = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
    HBITMAP hbm_old = (HBITMAP) SelectObject(hdc_buffer, hbm_buffer);

    HDC hdc_mem1 = CreateCompatibleDC(hdc);
    HBITMAP hbm_mem1_old = (HBITMAP) SelectObject(hdc_mem1, hbm_city);
    BitBlt(hdc_buffer, 0, 0, bm_city.bmWidth, bm_city.bmHeight, hdc_mem1, 0, 0, SRCCOPY);
    SelectObject(hdc_mem1, woman.direction == LEFT ? hbm_woman : hbm_woman_right);
    BitBlt(hdc_buffer, woman.x, woman.y, woman.width, woman.height, hdc_mem1, (woman.direction == LEFT ? woman.counter_left_x : woman.counter_right_x) * woman.width, woman.counter_y * woman.height, SRCAND);
    SelectObject(hdc_mem1, woman.direction == LEFT ? hbm_woman_black : hbm_woman_right_black);
    BitBlt(hdc_buffer, woman.x, woman.y, woman.width, woman.height, hdc_mem1, (woman.direction == LEFT ? woman.counter_left_x : woman.counter_right_x) * woman.width, woman.counter_y * woman.height, SRCPAINT);
    SelectObject(hdc_mem1, hbm_mem1_old);
    DeleteObject(hdc_mem1);

    HDC hdc_mem2 = CreateCompatibleDC(hdc);
    HBITMAP hbm_mem2_old = (HBITMAP) SelectObject(hdc_mem2, bike.direction == LEFT ? hbm_bike : hbm_bike_right);
    BitBlt(hdc_buffer, bike.x, bike.y, bike.width, bike.height, hdc_mem2, (bike.direction == LEFT ? bike.counter_left_x : bike.counter_right_x) * bike.width, bike.counter_y * bike.height, SRCAND);
    SelectObject(hdc_mem2, bike.direction == LEFT ? hbm_bike_black : hbm_bike_right_black);
    BitBlt(hdc_buffer, bike.x, bike.y, bike.width, bike.height, hdc_mem2, (bike.direction == LEFT ? bike.counter_left_x : bike.counter_right_x) * bike.width, bike.counter_y * bike.height, SRCPAINT);
    SelectObject(hdc_mem2, hbm_mem2_old);
    DeleteObject(hdc_mem2);

    HDC hdc_mem3;
    for (const auto &b: bikes) {
        hdc_mem3 = CreateCompatibleDC(hdc);
        HBITMAP hbm_mem3_old = (HBITMAP) SelectObject(hdc_mem3, hbm_bike);
        BitBlt(hdc_buffer, b.x, b.y, b.width, b.height, hdc_mem3, b.counter_left_x * b.width, b.counter_y * b.height, SRCAND);
        SelectObject(hdc_mem3, hbm_bike_black);
        BitBlt(hdc_buffer, b.x, b.y, b.width, b.height, hdc_mem3, b.counter_left_x * b.width, b.counter_y * b.height, SRCPAINT);
        SelectObject(hdc_mem3, hbm_mem3_old);
        DeleteObject(hdc_mem3);
    }

    BitBlt(hdc, 0, 0, rect.right, rect.bottom, hdc_buffer, 0, 0, SRCCOPY);

    SelectObject(hdc_buffer, hbm_old);
    DeleteObject(hdc_buffer);
    DeleteObject(hbm_buffer);
}

void render(HWND hwnd) {
    HDC hdc = GetDC(hwnd);
    draw(hdc);
    ReleaseDC(hwnd, hdc);
}

void add_new_bike() {
    Object new_bike;
    initialize_object(&new_bike, &bm_bike);
    new_bike.dx = -BIKE_DX+2;

    bikes.push_back(new_bike);
}
