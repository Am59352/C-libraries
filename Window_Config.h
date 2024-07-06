#pragma once
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
 
class Win {
    public:
    int WinPosX;
    int WinPosY;
    int WinSizeX;
    int WinSizeY;
    bool Maxbttn;
    bool Minbttn;
    bool ScbarVert;
    bool ScbarHorz;
    bool Minimize;
    bool Maximize;
    bool Window;
    bool Closebttn;
    char title[64];
    string Windowtitle;

    void Update() {
     HWND hwnd = GetConsoleWindow();
     
    strcpy(title, Windowtitle.c_str());

    if (Maxbttn == false) {
        SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
    } else if (Maxbttn == true) {
        SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) | WS_MAXIMIZEBOX);
    }

    if (Minbttn == false) {
        SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);
    } else if (Minbttn == true) {
        SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) | WS_MINIMIZEBOX);
    }

    if (Closebttn == false) {
        EnableMenuItem(GetSystemMenu(hwnd, FALSE), SC_CLOSE,MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);
    } else if (Closebttn == true) {
        EnableMenuItem(GetSystemMenu(hwnd, FALSE), SC_CLOSE,MF_BYCOMMAND | MF_ENABLED);
    }

      if (Minimize == true) {
        ShowWindow(hwnd,SW_MINIMIZE);
      } else if(Minimize == false) {
        Sleep(30);
        ShowWindow(hwnd,SW_RESTORE);
      }

      if (Maximize == true) {
        ShowWindow(hwnd,SW_MAXIMIZE);
      } else if(Minimize == false) {
        Sleep(30);
        ShowWindow(hwnd,SW_RESTORE);
      }
          
    EnableWindow(hwnd,Window);

    MoveWindow(hwnd, 0, 0, WinSizeX, WinSizeY, TRUE);
    SetWindowPos(hwnd, NULL, WinPosX, WinPosY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    ShowScrollBar(GetConsoleWindow(), SB_VERT, ScbarVert);
    ShowScrollBar(GetConsoleWindow(), SB_HORZ, ScbarHorz);
    if (hwnd != NULL) {
        while (true) {
        SetWindowTextA(hwnd, title);  
        Sleep(10);
        }
        
    } else {
        printf("Error\n");
    }
 
}
    };