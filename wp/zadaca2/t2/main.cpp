#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

static std::vector<std::queue<std::string>> cmds;

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

    std::ifstream input("koordinate.txt");
    std::string line, token;

    while(std::getline(input, line)){
        std::stringstream ss(line);
        std::queue<std::string> q;
        while (ss.good()) {
            ss >> token;
            q.push(token);
        }
        cmds.push_back(q);
    }

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

std::string peekAndPop(std::queue<std::string> &cmd) {
    std::string s = cmd.front();
    cmd.pop();
    return s;
}

void applyPen(HDC hdc, std::queue<std::string> &cmd) {
    int pen_width, red, green, blue;

    if (cmd.size() != 4) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Applying pen ..." << std::endl;
    pen_width = std::stoi(peekAndPop(cmd));
    red = std::stoi(peekAndPop(cmd));
    green = std::stoi(peekAndPop(cmd));
    blue = std::stoi(peekAndPop(cmd));
    HPEN hpen = CreatePen(PS_DASH, pen_width, RGB(red,green,blue));

    SelectObject(hdc, hpen);
}

void drawCircle(HDC hdc, std::queue<std::string> &cmd, int cx, int cy) {
    int x, y, r;

    if (cmd.size() != 3) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Drawing circle ..." << std::endl;
    x = std::stoi(peekAndPop(cmd));
    y = std::stoi(peekAndPop(cmd));
    r = std::stoi(peekAndPop(cmd));

    Ellipse(hdc, (x-r)*cx/100, (y-r)*cy/100, (x+r)*cx/100, (y+r)*cy/100);
}

void drawLine(HDC hdc, std::queue<std::string> &cmd, int cx, int cy) {
    int x1, y1, x2, y2;

    if (cmd.size() != 4) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Drawing line ..." << std::endl;
    x1 = std::stoi(peekAndPop(cmd));
    y1 = std::stoi(peekAndPop(cmd));
    x2 = std::stoi(peekAndPop(cmd));
    y2 = std::stoi(peekAndPop(cmd));

    MoveToEx(hdc, x1*cx/100, y1*cy/100, NULL);
    LineTo(hdc, x2*cx/100, y2*cy/100);
    MoveToEx(hdc, 0, 0, NULL);
}

void drawRectangle(HDC hdc, std::queue<std::string> &cmd, int cx, int cy) {
    int left, right, top, bottom;

    if (cmd.size() != 4) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Drawing rectangle ..." << std::endl;
    left = std::stoi(peekAndPop(cmd));
    top = std::stoi(peekAndPop(cmd));
    right = std::stoi(peekAndPop(cmd));
    bottom = std::stoi(peekAndPop(cmd));

    Rectangle(hdc, left*cx/100, top*cy/100, right*cx/100, bottom*cy/100);
}

void drawEllipse(HDC hdc, std::queue<std::string> &cmd, int cx, int cy) {
    int left, right, top, bottom;

    if (cmd.size() != 4) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Drawing ellipse ..." << std::endl;
    left = std::stoi(peekAndPop(cmd));
    top = std::stoi(peekAndPop(cmd));
    right = std::stoi(peekAndPop(cmd));
    bottom = std::stoi(peekAndPop(cmd));

    Ellipse(hdc, left*cx/100, top*cy/100, right*cx/100, bottom*cy/100);
}

void drawSquare(HDC hdc, std::queue<std::string> &cmd, int cx, int cy) {
    int x, y, a;

    if (cmd.size() != 3) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Drawing square ..." << std::endl;
    x = std::stoi(peekAndPop(cmd));
    y = std::stoi(peekAndPop(cmd));
    a = std::stoi(peekAndPop(cmd))/2;

    Rectangle(hdc, (x-a)*cx/100, (y-a)*cy/100, (x+a)*cx/100, (y+a)*cy/100);
}

void applyBrush(HDC hdc, std::queue<std::string> &cmd, bool hatched = false) {
    int red, green, blue;

    if (cmd.size() != 3) {
        throw std::invalid_argument("Unrecognized command");
    }

    std::cout << "Applying " << (hatched ? "hatched " : "solid ") << "brush ..." << std::endl;
    red = std::stoi(peekAndPop(cmd));
    green = std::stoi(peekAndPop(cmd));
    blue = std::stoi(peekAndPop(cmd));
    COLORREF color = RGB(red, green, blue);

    DeleteObject(SelectObject(hdc, hatched ? CreateHatchBrush(HS_BDIAGONAL, color) : CreateSolidBrush(color)));
}

void drawElement(HDC hdc, std::queue<std::string> &cmd, int cx, int cy) {
    const std::string c = peekAndPop(cmd);

    if (c == "C") {
        if (cmd.front() == "S") {
            cmd.pop();
            applyPen(hdc, cmd);
        } else {
            drawCircle(hdc, cmd, cx, cy);
        }
    } else if (c == "L") {
        drawLine(hdc, cmd, cx, cy);
    } else if (c == "R") {
        drawRectangle(hdc, cmd, cx, cy);
    } else if (c == "E") {
        drawEllipse(hdc, cmd, cx, cy);
    } else if (c == "S") {
        drawSquare(hdc, cmd, cx, cy);
    } else if (c == "B") {
        applyBrush(hdc, cmd);
    } else if (c == "H") {
        if (cmd.front() == "B") {
            cmd.pop();
            applyBrush(hdc, cmd, true);
        }
    } else {
        throw std::invalid_argument("Unrecognized command");
    }
}

/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;
    RECT rect;

    static int cx, cy;

    switch (message)                  /* handle the messages */
    {
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        case WM_PAINT:
            hdc = BeginPaint(hwnd, &ps);
            for (auto cmd: cmds) {
                drawElement(hdc, cmd, cx, cy);
            }
            EndPaint(hwnd, &ps);
            break;
        case WM_SIZE:
            cx = LOWORD(lParam);
            cy = HIWORD(lParam);
            GetClientRect(hwnd, &rect);
            InvalidateRect(hwnd, &rect, true);
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
