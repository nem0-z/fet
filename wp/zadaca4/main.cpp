#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include "resources.h"
#include "Equation.h"
#include "Helper.h"

Equation equation;
extern Helper helper;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildWindowProcedure (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd, hwndChild;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "Parent";
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_HREDRAW | CS_VREDRAW;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hIconSm = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hCursor = LoadCursor (hThisInstance, MAKEINTRESOURCE(IDC_CURSOR));
    wincl.lpszMenuName = "MyMenu";
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl)) //Register parent window
        return 0;

    wincl.lpszClassName = "Child";
    wincl.lpfnWndProc = ChildWindowProcedure;
    wincl.lpszMenuName = NULL;

    if (!RegisterClassEx (&wincl)) //Register child window
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           "Parent",         /* Classname */
           _T("Iscrtavanje"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           700,                 /* The programs width */
           500,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    hwndChild = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           "Child",         /* Classname */
           _T("Unos"),       /* Title Text */
           WS_CAPTION,       /* Title only */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           350,                 /* The programs width */
           250,                 /* and height in pixels */
           hwnd,                /* The window is a child-window to hwnd */
           NULL,                /* No menu */
           (HINSTANCE) GetWindowLong(hwnd, GWLP_HINSTANCE),       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    ShowWindow(hwndChild, nCmdShow);

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

    switch (message)                  /* handle the messages */
    {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case MENU_ABOUT:
                    MessageBox(hwnd, "Zlatan Radovanovic, 18117", "Author", MB_ICONINFORMATION);
                    break;
                case MENU_EXIT:
                    PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
                    break;
            }
            return 0;
        case WM_USER:
            if (wParam == CMD_DRAW)
                InvalidateRect(hwnd, NULL, true);
            return 0;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            //TODO
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

LRESULT CALLBACK ChildWindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
            return helper.createControls(hwnd);
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case IDB_0:
                    SetWindowText(GetDlgItem(hwnd, EDIT_A), "0");
                    SetWindowText(GetDlgItem(hwnd, EDIT_B), "0");
                    SetWindowText(GetDlgItem(hwnd, EDIT_C), "0");
                    SetWindowText(GetDlgItem(hwnd, EDIT_D), "0");
                    break;
                case IDB_CRTAJ:
                    if (helper.parseInput(hwnd) == PARSE_OK){
                        HWND parent = GetWindow(hwnd, GW_OWNER);
                        SendMessage(parent, WM_USER, (WPARAM)CMD_DRAW, 0);
                    }
                    break;
            }
            return 0;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}
