#include <iostream>
#include <Windows.h>

using namespace std;

void GetDesktopResolution(int& horizontal, int& vertical);

int main()
{
    cout << "Starting..." << endl;

    int movement = 1;

    while (true)
    {
        Sleep(100);

        POINT p;
        if (GetCursorPos(&p))
        {

            cout << "Moving Cursor..." <<  movement << endl;

            SetCursorPos(p.x + movement, p.y);

            movement = -movement;
        }
    }

    cout << "Terminated..." << endl;

    return 0;
}
