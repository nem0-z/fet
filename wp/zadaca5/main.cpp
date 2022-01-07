#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <list>
#include <algorithm>

#ifndef KEYS_MAGIC
#define PRESSED(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define WAS_PRESSED(vk_code) ((GetAsyncKeyState(vk_code) & 0x0001) ? 1 : 0)
#define IS_OR_WAS_PRESSED(vk_code) ((GetAsyncKeyState(vk_code) & 0x8001) ? 1 : 0)
#endif

HBITMAP hbm_tank, hbm_tank_black,
        hbm_explosion, hbm_explosion_black,
        hbm_projectile, hbm_projectile_black;
BITMAP bm_tank, bm_explosion, bm_projectile;
RECT rect;

const int STEP = 4;

class Object {
    public:
    int x = 0;
    int y = 0;
    int width = 0;
    int height = 0;
};
Object tank;
std::list<Object> projectiles;

class Explosion : public Object {
    public:
    int counter_x = 0;
    int counter_y = 0;

    Explosion() {
        width = bm_explosion.bmWidth / 5;
        height = bm_explosion.bmHeight / 5;
        x = projectiles.front().x; //Explosion will only be created when there is at least one projectile so this is fine
        y = 5;
    }
};
std::list<Explosion> explosions;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("HW5");

void initialize(HWND hwnd) {
    GetClientRect(hwnd, &rect);

    hbm_tank = (HBITMAP) LoadImage(NULL, "tenkovi.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_tank_black = (HBITMAP) LoadImage(NULL, "tenkovi_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_projectile = (HBITMAP) LoadImage(NULL, "hamburger.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_projectile_black = (HBITMAP) LoadImage(NULL, "hamburger_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_explosion = (HBITMAP) LoadImage(NULL, "eksplozija.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
    hbm_explosion_black = (HBITMAP) LoadImage(NULL, "eksplozija_black.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

    GetObject(hbm_tank, sizeof(BITMAP), &bm_tank);
    GetObject(hbm_explosion, sizeof(BITMAP), &bm_explosion);
    GetObject(hbm_projectile, sizeof(BITMAP), &bm_projectile);

    tank.width = bm_tank.bmWidth / 5;
    tank.height = bm_tank.bmHeight / 3;
    tank.x = (rect.right - tank.width) / 2;
    tank.y = rect.bottom - tank.height;

}

void shootProjectile(int y_offset = 0) {
    Object newProjectile;
    newProjectile.height = bm_projectile.bmHeight;
    newProjectile.width = bm_projectile.bmWidth;
    newProjectile.x = tank.x + tank.width / 2 - 10;
    newProjectile.y = tank.y - y_offset;
    projectiles.push_back(newProjectile);
}

void shootTwoProjectiles() {
    shootProjectile();
    shootProjectile(-10);
}

void check_input() {
    if (PRESSED(VK_UP) && (tank.y > (tank.height))) {
        tank.y -= STEP;
    } else if (PRESSED(VK_DOWN) && (tank.y < (rect.bottom - tank.height))) {
        tank.y += STEP;
    } else if (PRESSED(VK_LEFT) && (tank.x > 0)) {
        tank.x -= STEP;
    } else if (PRESSED(VK_RIGHT) && (tank.x < (rect.right - tank.height))) {
        tank.x += STEP;
    } else if (PRESSED(VK_SPACE) && WAS_PRESSED(VK_SHIFT)) {
        shootTwoProjectiles();
    }
}

bool explosionDone(Explosion &explosion) {
    explosion.counter_x++;
    if (explosion.counter_x >= 5) {
        explosion.counter_x = 0;
        explosion.counter_y++;
        if (explosion.counter_y >= 5)
            return true;
    }

    return false;
}

void update(HWND hwnd) {
    GetClientRect(hwnd, &rect);

    for (auto &projectile: projectiles) {
        projectile.y -= STEP;
    }

    if (!projectiles.empty() && projectiles.front().y <= 0) {
        explosions.push_back(Explosion());
        projectiles.pop_front();
    }

    std::remove_if(explosions.begin(), explosions.end(), explosionDone);
}

void draw(HDC hdc, HWND hwnd) {
    HDC hdc_buffer = CreateCompatibleDC(hdc);
    HBITMAP hbm_buffer = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
    HBITMAP hbm_old = (HBITMAP) SelectObject(hdc_buffer, hbm_buffer);

    HBRUSH hbrush = CreateSolidBrush(RGB(150, 200, 0));
    GetClientRect(hwnd, &rect);
    FillRect(hdc_buffer, &rect, hbrush);
    DeleteObject(hbrush);

    HDC hdc_mem1 = CreateCompatibleDC(hdc);
    HBITMAP hbm_mem1_old = (HBITMAP) SelectObject(hdc_mem1, hbm_tank);
    BitBlt(hdc_buffer, tank.x, tank.y, tank.width, tank.height, hdc_mem1, 3 * tank.width, 2 * tank.height, SRCAND);
    SelectObject(hdc_mem1, hbm_tank_black);
    BitBlt(hdc_buffer, tank.x, tank.y, tank.width, tank.height, hdc_mem1, 3 * tank.width, 2 * tank.height, SRCPAINT);
    SelectObject(hdc_mem1, hbm_mem1_old);
    DeleteObject(hdc_mem1);

    HDC hdc_mem2;
    for (const auto &p: projectiles) {
        hdc_mem2 = CreateCompatibleDC(hdc);
        HBITMAP hbm_mem2_old = (HBITMAP) SelectObject(hdc_mem2, hbm_projectile);
        BitBlt(hdc_buffer, p.x, p.y, p.width, p.height, hdc_mem2, 0, 0, SRCAND);
        SelectObject(hdc_mem2, hbm_projectile_black);
        BitBlt(hdc_buffer, p.x, p.y, p.width, p.height, hdc_mem2, 0, 0, SRCPAINT);
        SelectObject(hdc_mem2, hbm_mem2_old);
        DeleteObject(hdc_mem2);
    }

    HDC hdc_mem3;
    for (const auto &e: explosions) {
        hdc_mem3 = CreateCompatibleDC(hdc);
        HBITMAP hbm_mem3_old = (HBITMAP) SelectObject(hdc_mem3, hbm_explosion);
        BitBlt(hdc_buffer, e.x, e.y, e.width, e.height, hdc_mem3, e.counter_x * e.width, e.counter_y * e.height, SRCAND);
        SelectObject(hdc_mem3, hbm_explosion_black);
        BitBlt(hdc_buffer, e.x, e.y, e.width, e.height, hdc_mem3, e.counter_x * e.width, e.counter_y * e.height, SRCPAINT);
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
    draw(hdc, hwnd);
    ReleaseDC(hwnd, hdc);
}

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("World Of Tanks"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    DWORD time_begin;
    initialize(hwnd);
    for (;;) {
        if (PeekMessage(&messages, NULL, 0, 0, PM_REMOVE)) {
            if (messages.message == WM_QUIT) {
                PostQuitMessage(0);
                break;
            }

            DispatchMessage(&messages);
            TranslateMessage(&messages);
        }

        time_begin = GetTickCount();
        check_input();
        update(hwnd);
        render(hwnd);

        while (GetTickCount() - time_begin < 20) {
            Sleep(30);
        }
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_LBUTTONDOWN:
            shootProjectile();
            break;
        case WM_KEYDOWN:
            if (wParam == VK_SHIFT)
                shootProjectile();
            break;
        case WM_MOUSEMOVE:
            tank.x = LOWORD(lParam) - tank.width / 2;
            tank.y = HIWORD(lParam) - tank.height / 2;
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
