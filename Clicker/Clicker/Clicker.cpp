#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

void Mix(short int a[]) {
    short index;
    for (int i = 1; i < 30; i++) {
        index = rand() % i;
        swap(a[i], a[index]);

    }
}

void left_click() {
    mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, 0, 0);
}
short int pro_() {
    return rand() % 20 + 40;
}
int main()
{

    short int now = 0;
    short int a[30] = { 28, 31, 26, 40, 32, 29, 33, 30, 25, 26, 27, 28, 29, 30, 31, 27, 25, 40, 29, 25, 31, 33, 24, 25, 26, 29, 28, 24, 30, 31 };

    while (true)
        if (GetAsyncKeyState(VK_LBUTTON) && GetAsyncKeyState(VK_CONTROL))
        {
            if (now == 30) {
                Mix(a);
                now = 0;
            }
            if ((now + 1) % 7 == 0)
                Sleep(pro_());
            else
                Sleep(a[now]);
            left_click();
            now++;
        }

    return 0;
}