#pragma once
#include <windows.h>

extern LRESULT CALLBACK WndProc(HWND hWnd, UINT uiMsg, WPARAM wParam, LPARAM lParam);
void Close(UINT Msg, HWND hWnd);
void Destroy(UINT Msg, HWND hWnd);