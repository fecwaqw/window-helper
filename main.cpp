#include <windows.h>

bool key(int key)
{
    return (GetAsyncKeyState(key) & 0x8000);
}

int main()
{
    HWND window;
    while (1)
    {
        if (key(VK_SHIFT) && key('R'))
        {
            window = GetForegroundWindow();
        }
        if (key(VK_SHIFT) && key('Z'))
        {
            ShowWindow(window, SW_HIDE);
        }
        if (key(VK_SHIFT) && key('X'))
        {
            ShowWindow(window, SW_SHOW);
        }
        Sleep(100);
    }
    return 0;
}