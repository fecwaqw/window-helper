#include "wh.hpp"
using namespace std;

int main()
{
    wh::initHotKey();
    MSG msg = {0};
    HWND tmpHWND = NULL;
    bool show = false;
    while (GetMessage(&msg, NULL, 0, 0) != 0)
        if (msg.message == WM_HOTKEY)
        {
            if (msg.wParam == wh::hotKeyId.at(0) && show == true)
            {
                tmpHWND = GetForegroundWindow();
                wh::hWndList.push_back(tmpHWND);
                show = true;
            }
            if (msg.wParam == wh::hotKeyId.at(1))
            {
                if (show)
                    ShowWindow(tmpHWND, SW_HIDE);
                else
                    ShowWindow(tmpHWND, SW_SHOW);
                show = !show;
            }
        }
    return 0;
}