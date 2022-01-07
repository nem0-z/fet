#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include "resources.h"

#define BUF_SIZE 20

struct DrawHelper{
    int x;
    int y;
    int a;
    int b;
    int r;
    int shape;
    int penWidth;
    int penType;
    int color;
};

std::vector<DrawHelper> drawHelpers;
bool rectangle = false;
bool ellipse = false;
bool solidPen = true;

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
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hIconSm = LoadIcon (hThisInstance, MAKEINTRESOURCE(IDI_ICON));
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = "MyMenu";                 /* No menu */
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
           "Parent",         /* Classname */
           _T("Drawing tool"),       /* Title Text */
           WS_SYSMENU, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           800,                 /* The programs width */
           800,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    wincl.lpszClassName = "Child";
    wincl.lpfnWndProc = ChildWindowProcedure;
    wincl.lpszMenuName = NULL;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwndChild = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           "Child",         /* Classname */
           _T("Controls"),       /* Title Text */
           WS_BORDER, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           270,                 /* The programs width */
           600,                 /* and height in pixels */
           hwnd,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwndChild, nCmdShow);

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
    static RECT rect;
    static PAINTSTRUCT ps;
    static HPEN hpen;
    const HBRUSH hbrush = CreateSolidBrush(RGB(0, 0, 255));

    switch (message)                  /* handle the messages */
    {
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case MENU_INFO:
                    MessageBox(hwnd, "Zlatan Radovanovic, 18117", "Author", MB_ICONINFORMATION);
                    break;
                case MENU_CLEAR:
                    drawHelpers.clear();
                    GetClientRect(hwnd, &rect);
                    InvalidateRect(hwnd, &rect, true);
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
        {
            hdc = BeginPaint(hwnd, &ps);
            for (const auto& drawHelper: drawHelpers) {
                if (drawHelper.shape != RECTANGLE && drawHelper.shape != ELLIPSE) {
                    DeleteObject(hpen);
                    DeleteObject(hbrush);
                    EndPaint(hwnd, &ps);
                    return -1;
                }

                hpen = CreatePen((drawHelper.penType == PEN_SOLID ? PS_SOLID : PS_DASH), drawHelper.penWidth, RGB(255, 0, 0));
                SelectObject(hdc, hpen);

                SelectObject(hdc, hbrush);

                if (drawHelper.shape == RECTANGLE) {
                    Rectangle(hdc, drawHelper.x, drawHelper.y, drawHelper.x + drawHelper.a, drawHelper.y + drawHelper.b);
                } else if (drawHelper.shape == ELLIPSE) {
                    Ellipse(hdc, drawHelper.x, drawHelper.y, drawHelper.x + drawHelper.a, drawHelper.y + drawHelper.b);
                }

                DeleteObject(hpen);
            }

            DeleteObject(hbrush);
            EndPaint(hwnd, &ps);
        }
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
    static char textBuffer[BUF_SIZE];
    static int val;

    switch (message)                  /* handle the messages */
    {
        case WM_CREATE:
        {
            HINSTANCE hinst = (HINSTANCE) GetWindowLong(hwnd,GWLP_HINSTANCE);

            CreateWindow("button","Shapes",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
            10,10,240,100,hwnd,NULL,hinst,NULL);

            CreateWindow("button",NULL,WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
            20,40,15,15,hwnd,(HMENU) RADIO_RECT,hinst,NULL);
            CreateWindow("static","Rectangle",WS_CHILD | WS_VISIBLE | SS_CENTER,
            45,40,80,15,hwnd,NULL,hinst,NULL);

            CreateWindow("button",NULL,WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
            20,80,15,15,hwnd,(HMENU) RADIO_ELLIPSE,hinst,NULL);
            CreateWindow("static","Ellipse",WS_CHILD | WS_VISIBLE | SS_CENTER,
            45,80,80,15,hwnd,NULL,hinst,NULL);

            CreateWindow("button","Size",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
            10,130,240,140,hwnd,NULL,hinst,NULL);

            CreateWindow("static","x:",WS_CHILD | WS_VISIBLE,
            40,160,15,15,hwnd,(HMENU) NULL,hinst,NULL);
            CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER,
            60,160,30,15,hwnd,(HMENU) EDIT_X,hinst,NULL);

            CreateWindow("static","y:",WS_CHILD | WS_VISIBLE,
            160,160,15,15,hwnd,(HMENU) NULL,hinst,NULL);
            CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER,
            180,160,30,15,hwnd,(HMENU) EDIT_Y,hinst,NULL);

            CreateWindow("static","a:",WS_CHILD | WS_VISIBLE,
            40,210,15,15,hwnd,(HMENU) NULL,hinst,NULL);
            CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER,
            60,210,30,15,hwnd,(HMENU) EDIT_A,hinst,NULL);

            CreateWindow("static","b:",WS_CHILD | WS_VISIBLE,
            160,210,15,15,hwnd,(HMENU) NULL,hinst,NULL);
            CreateWindow("edit",NULL,WS_CHILD | WS_VISIBLE | WS_BORDER,
            180,210,30,15,hwnd,(HMENU) EDIT_B,hinst,NULL);

            CreateWindow("button","Pen options",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
            10,280,240,140,hwnd,NULL,hinst,NULL);

            CreateWindow("static","Width:",WS_CHILD | WS_VISIBLE,
            60,320,60,15,hwnd,(HMENU) NULL,hinst,NULL);
            CreateWindow("edit","2",WS_CHILD | WS_VISIBLE | WS_BORDER,
            140,320,30,15,hwnd,(HMENU) EDIT_PEN_WIDTH,hinst,NULL);

            CreateWindow("button",NULL,WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
            50,350,15,15,hwnd,(HMENU) RADIO_PEN1,hinst,NULL);
            CreateWindow("static","Solid",WS_CHILD | WS_VISIBLE | SS_CENTER,
            80,350,100,15,hwnd,NULL,hinst,NULL);
            SendMessage(GetDlgItem(hwnd, RADIO_PEN1), BM_SETCHECK, BST_CHECKED, 0);

            CreateWindow("button",NULL,WS_CHILD | WS_VISIBLE | BS_RADIOBUTTON,
            50,380,15,15,hwnd,(HMENU) RADIO_PEN2,hinst,NULL);
            CreateWindow("static","Dashed",WS_CHILD | WS_VISIBLE | SS_CENTER,
            80,380,100,15,hwnd,NULL,hinst,NULL);

            CreateWindow("button","Draw",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | SS_CENTER,
            110,450,60,30,hwnd,(HMENU) IDB_DRAW,hinst,NULL);

            return 0;
        }
        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case RADIO_RECT:
                    SendMessage((HWND) lParam,BM_SETCHECK,
                                !SendMessage((HWND) lParam,BM_GETCHECK,0,0),0);
                    SendMessage(GetDlgItem(hwnd, RADIO_ELLIPSE), BM_SETCHECK, BST_UNCHECKED, 0);
                    rectangle = true;
                    ellipse = false;
                    break;
                case RADIO_ELLIPSE:
                    SendMessage((HWND) lParam,BM_SETCHECK,
                                !SendMessage((HWND) lParam,BM_GETCHECK,0,0),0);
                    SendMessage(GetDlgItem(hwnd, RADIO_RECT), BM_SETCHECK, BST_UNCHECKED, 0);
                    ellipse = true;
                    rectangle = false;
                    break;
                case RADIO_PEN1:
                    SendMessage((HWND) lParam,BM_SETCHECK,
                                !SendMessage((HWND) lParam,BM_GETCHECK,0,0),0);
                    SendMessage(GetDlgItem(hwnd, RADIO_PEN2), BM_SETCHECK, BST_UNCHECKED, 0);
                    solidPen = true;
                    break;
                case RADIO_PEN2:
                    SendMessage((HWND) lParam,BM_SETCHECK,
                                !SendMessage((HWND) lParam,BM_GETCHECK,0,0),0);
                    SendMessage(GetDlgItem(hwnd, RADIO_PEN1), BM_SETCHECK, BST_UNCHECKED, 0);
                    solidPen = false;
                    break;
                case IDB_DRAW:
                {
                    DrawHelper drawHelper;

                    if (!rectangle && !ellipse)
                        return MessageBox(hwnd, "Please select a shape", "Error", MB_ICONERROR);

                    GetWindowText(GetDlgItem(hwnd, EDIT_X), textBuffer, BUF_SIZE);
                    if ((val = atoi(textBuffer))){
                        if (val < 0)
                            return MessageBox(hwnd, "Coordinates can not be negative", "Error", MB_ICONASTERISK);
                        drawHelper.x = val;
                    }
                    else if (*textBuffer == '0')
                        drawHelper.x = 0;
                    else
                        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

                    GetWindowText(GetDlgItem(hwnd, EDIT_Y), textBuffer, BUF_SIZE);
                    if ((val = atoi(textBuffer))){
                        if (val < 0)
                            return MessageBox(hwnd, "Coordinates can not be negative", "Error", MB_ICONASTERISK);
                        drawHelper.y = val;
                    }
                    else if (*textBuffer == '0')
                        drawHelper.y = 0;
                    else
                        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

                    GetWindowText(GetDlgItem(hwnd, EDIT_A), textBuffer, BUF_SIZE);
                    if ((val = atoi(textBuffer))){
                        if (val < 0)
                            return MessageBox(hwnd, "Coordinates can not be negative", "Error", MB_ICONASTERISK);
                        drawHelper.a = val;
                    }
                    else if (*textBuffer == '0')
                        drawHelper.a = 0;
                    else
                        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

                    GetWindowText(GetDlgItem(hwnd, EDIT_B), textBuffer, BUF_SIZE);
                    if ((val = atoi(textBuffer))){
                        if (val < 0)
                            return MessageBox(hwnd, "Coordinates can not be negative", "Error", MB_ICONASTERISK);
                        drawHelper.b = val;
                    }
                    else if (*textBuffer == '0')
                        drawHelper.b = 0;
                    else
                        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

                    GetWindowText(GetDlgItem(hwnd, EDIT_PEN_WIDTH), textBuffer, BUF_SIZE);
                    if ((val = atoi(textBuffer)) && val >= 1)
                        drawHelper.penWidth = val;
                    else
                        return MessageBox(hwnd, "Pen width must be at least 1", "Error", MB_ICONERROR);

                    drawHelper.penType = solidPen ? PEN_SOLID : PEN_DASH;
                    drawHelper.shape = rectangle ? RECTANGLE : ELLIPSE;

                    drawHelpers.push_back(drawHelper);

                    HWND parent = GetWindow(hwnd, GW_OWNER);
                    SendMessage(parent, WM_USER, (WPARAM)CMD_DRAW, 0);
                }
                break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
