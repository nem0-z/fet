#include "Helper.h"

Helper helper;
extern Equation equation;

int Helper::parseInput(HWND hwnd) {
    int val;

    GetWindowText(GetDlgItem(hwnd, EDIT_A), helper.textBuffer, BUF_SIZE);
    if ((val = atoi(helper.textBuffer)))
        equation.a = val;
    else if (*helper.textBuffer == '0')
        equation.a = 0;
    else
        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

    GetWindowText(GetDlgItem(hwnd, EDIT_B), helper.textBuffer, BUF_SIZE);
    if ((val = atoi(helper.textBuffer)))
        equation.b = val;
    else if (*helper.textBuffer == '0')
        equation.b = 0;
    else
        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

    GetWindowText(GetDlgItem(hwnd, EDIT_C), helper.textBuffer, BUF_SIZE);
    if ((val = atoi(helper.textBuffer)))
        equation.c = val;
    else if (*helper.textBuffer == '0')
        equation.c = 0;
    else
        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

    GetWindowText(GetDlgItem(hwnd, EDIT_D), helper.textBuffer, BUF_SIZE);
    if ((val = atoi(helper.textBuffer)))
        equation.d = val;
    else if (*helper.textBuffer == '0')
        equation.d = 0;
    else
        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

    GetWindowText(GetDlgItem(hwnd, EDIT_XMAX), helper.textBuffer, BUF_SIZE);
    if ((val = atoi(helper.textBuffer)))
        equation.xmax = val;
    else if (*helper.textBuffer == '0')
        equation.xmax = 0;
    else
        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

    GetWindowText(GetDlgItem(hwnd, EDIT_YMAX), helper.textBuffer, BUF_SIZE);
    if ((val = atoi(helper.textBuffer)))
        equation.ymax = val;
    else if (*helper.textBuffer == '0')
        equation.ymax = 0;
    else
        return MessageBox(hwnd, "Please fill in all required fields", "Error", MB_ICONERROR);

    int iIndex = SendMessage(helper.equationList, LB_GETCURSEL, 0, 0);
    if (iIndex == -1)
        return MessageBox(hwnd, "Please select equation", "Error", MB_ICONERROR);
    equation.type = iIndex; //enum of equation types sorted in same way as items in list

    return PARSE_OK;
}

int Helper::createControls(HWND hwnd) {
    HINSTANCE hinst = (HINSTANCE) GetWindowLong(hwnd,GWLP_HINSTANCE);

    CreateWindow("button","Koeficijenti",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
    5,10,110,125,hwnd,NULL,hinst,NULL);
    CreateWindow("edit","",WS_CHILD | WS_VISIBLE | WS_BORDER,
    30,35,80,20,hwnd,(HMENU) EDIT_A,hinst,NULL);
    CreateWindow("edit","",WS_CHILD | WS_VISIBLE | WS_BORDER,
    30,60,80,20,hwnd,(HMENU) EDIT_B,hinst,NULL);
    CreateWindow("edit","",WS_CHILD | WS_VISIBLE | WS_BORDER,
    30,85,80,20,hwnd,(HMENU) EDIT_C,hinst,NULL);
    CreateWindow("edit","",WS_CHILD | WS_VISIBLE | WS_BORDER,
    30,110,80,20,hwnd,(HMENU) EDIT_D,hinst,NULL);
    CreateWindow("static","a:",WS_CHILD | WS_VISIBLE | SS_CENTER,
    10,35,15,20,hwnd,(HMENU) NULL,hinst,NULL);
    CreateWindow("static","b:",WS_CHILD | WS_VISIBLE | SS_CENTER,
    10,60,15,20,hwnd,(HMENU) NULL,hinst,NULL);
    CreateWindow("static","c:",WS_CHILD | WS_VISIBLE | SS_CENTER,
    10,85,15,20,hwnd,(HMENU) NULL,hinst,NULL);
    CreateWindow("static","d:",WS_CHILD | WS_VISIBLE | SS_CENTER,
    10,110,15,20,hwnd,(HMENU) NULL,hinst,NULL);

    CreateWindow("button","Jednacina",WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
    140,10,190,100,hwnd,NULL,hinst,NULL);
    helper.equationList = CreateWindow ("listbox",NULL,WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_BORDER,
                            145,30,180,80,hwnd,(HMENU) EQ_LIST,
                            (HINSTANCE)GetWindowLong(hwnd,GWLP_HINSTANCE), NULL);
    SendMessage(helper.equationList,LB_ADDSTRING,0,(LPARAM)"y = ax + b");
    SendMessage(helper.equationList,LB_ADDSTRING,0,(LPARAM)"y = ax2 + bx + c");
    SendMessage(helper.equationList,LB_ADDSTRING,0,(LPARAM)"y = ax3 + bx2 + cx + d");

    CreateWindow("static","Xmax:",WS_CHILD | WS_VISIBLE,
    140,120,50,15,hwnd,(HMENU) NULL,hinst,NULL);
    CreateWindow("edit","",WS_CHILD | WS_VISIBLE | WS_BORDER,
    195,120,35,15,hwnd,(HMENU) EDIT_XMAX,hinst,NULL);
    CreateWindow("static","Ymax:",WS_CHILD | WS_VISIBLE,
    240,120,50,15,hwnd,(HMENU) NULL,hinst,NULL);
    CreateWindow("edit","",WS_CHILD | WS_VISIBLE | WS_BORDER,
    295,120,35,15,hwnd,(HMENU) EDIT_YMAX,hinst,NULL);

    CreateWindow("button","0",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | SS_CENTER,
    5,145,110,20,hwnd,(HMENU) IDB_0,hinst,NULL);
    CreateWindow("button","Crtaj",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | SS_CENTER,
    190,145,110,20,hwnd,(HMENU) IDB_CRTAJ,hinst,NULL);

    return 0;
}
