#pragma once
#include <string>
#include <Windows.h>
namespace font
{
void drawString(LPCTSTR str, HDC hdc, HWND hWnd);

}


using namespace font;