#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    cout << "Starting..." << endl;

    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0;
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    int movement = 1;

    while (true)
    {
        Sleep(1000);

        POINT p;
        if (GetCursorPos(&p))
        {
            cout << "Pressing Control Key..." << endl;

            ip.ki.wVk = VK_CONTROL;
            ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
            ip.ki.wVk = VK_CONTROL;
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));

            cout << "Moving Cursor..." <<  movement << endl;

            SetCursorPos(p.x + movement, p.y);

            movement = -movement;
        }
    }

    cout << "Terminated..." << endl;

    return 0;
}
