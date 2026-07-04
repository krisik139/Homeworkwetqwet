#include <iostream>

using namespace std;

int main() {
    system("chcp 1251>null");
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = 99 - (i * 3);
    }

    cout << "спадаючий масив: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}