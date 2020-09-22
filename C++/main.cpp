#include <iostream>

#ifdef _WIN32
#include <Windows.h>

void runLoop() {
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
            std::cout << "Pressing Control Key..." << std::endl;

            ip.ki.wVk = VK_CONTROL;
            ip.ki.dwFlags = 0; // 0 for key press
            SendInput(1, &ip, sizeof(INPUT));
            ip.ki.wVk = VK_CONTROL;
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));

            std::cout << "Moving Cursor..." <<  movement << std::endl;

            SetCursorPos(p.x + movement, p.y);

            movement = -movement;
        }
    }

    return
}

#else

int runLoop() {
    std::cout << "This program is not compatible with mac..." << std::endl;
    return 0;
}

#endif

using namespace std;

int main()
{
    std::cout << "Starting..." << std::endl;

    runLoop();

    std::cout << "Terminated..." << std::endl;

    return 0;
}
