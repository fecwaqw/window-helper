// wh.hpp
#ifndef _WH_HPP
#define _WH_HPP

// headfiles
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <tchar.h>
#include <vector>
#include <windows.h>

namespace wh
{
    static std::vector<HWND> hWndList;

    static std::vector<int> hotKeyId;

    // 初始化程序所有热键
    //
    void initHotKey()
    {
        hotKeyId.push_back(
            GlobalAddAtom(_T("get_hWnd")) - 0xc000); // 热键1
        if (!RegisterHotKey(                         // <shitf> + R
                NULL,                                // 用于获取窗口句柄
                hotKeyId.at(0),
                MOD_SHIFT,
                (int)'R'))
        {
            printf("无法注册热键 <shift> + R！请重启软件！");
            Sleep(5000);
            exit(0);
        }
        hotKeyId.push_back(
            GlobalAddAtom(_T("hide_or_display_window")) - 0xc000); // 热键2
        if (!RegisterHotKey(                                       // <shift> + Z
                NULL,                                              // 用于隐藏或显示窗口
                hotKeyId.at(1),
                MOD_SHIFT,
                (int)'Z'))
        {
            printf("无法注册热键 <shift> + Z！请重启软件！");
            Sleep(5000);
            exit(0);
        }
    }

} // namespace wh

#endif