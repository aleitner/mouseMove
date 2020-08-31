#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    cout << "Starting..." << endl;

    while (true)
    {
        Sleep(5000);

        POINT p;
        if (GetCursorPos(&p))
        {

            cout << "Moving Cursor..." << endl;

            SetCursorPos(0, 0);
            SetCursorPos(p.x, p.y);
        }
    }

    cout << "Terminated..." << endl;

    return 0;
}
