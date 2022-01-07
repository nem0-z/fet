#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(int)
void calculateElementsPosition(POINT*, int, int);

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

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
    wincl.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;                 /* Catch double-clicks */
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
           _T("Code::Blocks Template Windows App"),       /* Title Text */
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
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;
    HBRUSH brush;
    static int cx, cy;
    static POINT house[23];
    int elements[] = {3, 4, 4, 4, 4, 4};

    switch (message)                  /* handle the messages */
    {
        case WM_SIZE:
            cx = LOWORD(lParam);
            cy = HIWORD(lParam);
            calculateElementsPosition(house, cx, cy);
            break;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            GetClientRect(hwnd, &rect);
            brush = CreateHatchBrush(HS_BDIAGONAL, RGB(200,100,130));
            FillRect(hdc, &rect, brush);
            PolyPolygon(hdc, house, elements, ARRAY_SIZE(elements));
            DeleteObject(brush);
            EndPaint(hwnd, &ps);
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}

void calculateElementsPosition(POINT *house, int cx, int cy) {
        house[0].x = 6*cx/32; house[0].y = 8*cy/32;
        house[1].x = 24*cx/32; house[1].y = 8*cy/32;
        house[2].x = 15*cx/32; house[2].y = 2*cy/32; //roof

        house[3].x = 6*cx/32; house[3].y = 9*cy/32;
        house[4].x = 24*cx/32; house[4].y = 9*cy/32;
        house[5].x = 24*cx/32; house[5].y = 28*cy/32;
        house[6].x = 6*cx/32; house[6].y = 28*cy/32; //base

        house[7].x = 7*cx/32; house[7].y = 10*cy/32;
        house[8].x = 11*cx/32; house[8].y = 10*cy/32;
        house[9].x = 11*cx/32; house[9].y = 16*cy/32;
        house[10].x = 7*cx/32; house[10].y = 16*cy/32; //window1

        house[11].x = 13*cx/32; house[11].y = 10*cy/32;
        house[12].x = 17*cx/32; house[12].y = 10*cy/32;
        house[13].x = 17*cx/32; house[13].y = 16*cy/32;
        house[14].x = 13*cx/32; house[14].y = 16*cy/32; //window2

        house[15].x = 19*cx/32; house[15].y = 10*cy/32;
        house[16].x = 23*cx/32; house[16].y = 10*cy/32;
        house[17].x = 23*cx/32; house[17].y = 16*cy/32;
        house[18].x = 19*cx/32; house[18].y = 16*cy/32; //window3

        house[19].x = 13*cx/32; house[19].y = 28*cy/32;
        house[20].x = 13*cx/32; house[20].y = 20*cy/32;
        house[21].x = 17*cx/32; house[21].y = 20*cy/32;
        house[22].x = 17*cx/32; house[22].y = 28*cy/32; //door
}
