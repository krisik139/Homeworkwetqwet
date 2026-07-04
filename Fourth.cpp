#include <iostream>

using namespace std;

int main() {
    system("chcp 1251>null");

    //UTF 8 НЕ МАЄ БАЖАННЯ ПРАЦЮВАТИ

    int bigArr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int part1[5];
    int part2[5];

    for (int i = 0; i < 5; i++) {
        part1[i] = bigArr[i];
        part2[i] = bigArr[i + 5];
    }

    cout << "first ����� 5 ��������: ";
    for (int i = 0; i < 5; i++) cout << part1[i] << " ";
    cout << endl;

    cout << "secons ����� 5 ��������: ";
    for (int i = 0; i < 5; i++) cout << part2[i] << " ";
    cout << endl;

    return 0;
}