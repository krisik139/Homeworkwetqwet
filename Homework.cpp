#include <iostream>

using namespace std;

int main()
{
    system("chcp 1251>null");
    int poket;
    cout << "Введіть кишеньку(від 0 до 36): ";
    cin >> poket;
    
    if (poket < 0 || poket > 36) {
        cout << "КУДИ ЛІЗЕШ." << endl;
    }
    else if (poket == 0) {
        cout << "зелений" << endl;
    }
    else if (poket >= 1 && poket <= 10) {
        if (poket % 2 != 0) {
            cout << "червоний" << endl;
        }
        else {
            cout << "чорний" << endl;
        }
    }
    else if (poket >= 11 && poket <= 18) {
        if (poket % 2 != 0) {
            cout << "чорний" << endl;
        }
        else {
            cout << "червоний" << endl;
        }
    }
    else if (poket >= 19 && poket <= 28) {
        if (poket % 2 != 0) {
            cout << "червоний" << endl;
        }
        else {
            cout << "чорний" << endl;
        }
    }
    else if (poket >= 29 && poket <= 36) {
        if (poket % 2 != 0) {
            cout << "чорний" << endl;
        }
        else {
            cout << "червоний" << endl;
        }
    }

    return 0;
}