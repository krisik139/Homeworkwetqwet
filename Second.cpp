#include <iostream>
#include <cstdlib>
#include <ctime>
// ОЙ Я ЗАБУВСЯ ЕНКОДІНГ ПОСТАВИТИ (0(((00(((0(((0((0
using namespace std;

int main() {
    system("chcp 1251>null");
    srand(time(0));

    int profit[12];
    cout << "Ïðèáóòîê ô³ðìè çà 12 ì³ñÿö³â: " << endl;
    for (int i = 0; i < 12; i++) {
        profit[i] = rand() % 90000 + 10000;
        cout << i + 1 << " ì³ñ: " << profit[i] << " ãðí." << endl;
    }

    int start;
    int end;
    cout << "\nÂâåä³òü ïî÷àòêîâèé ì³ñÿöü ä³àïàçîíó (1-12): ";
    cin >> start;
    cout << "Ââåä³òü ê³íöåâèé ì³ñÿöü ä³àïàçîíó (1-12): ";
    cin >> end;

    int startIndex = start - 1;
    int endIndex = end - 1;
    
    int minProfit = profit[startIndex];
    int maxProfit = profit[startIndex];
    int minMonth = start;
    int maxMonth = start;

    for (int i = startIndex; i <= endIndex; i++) {
        if (profit[i] > maxProfit) {
            maxProfit = profit[i];
            maxMonth = i + 1;
        }
        if (profit[i] < minProfit) {
            minProfit = profit[i];
            minMonth = i + 1;
        }
    }

    cout << "\nÓ ä³àïàçîí³ â³ä " << start << " äî " << end << " ì³ñÿöÿ:" << endl;
    cout << "Ìàêñèìàëüíèé ïðèáóòîê: " << maxProfit << " ãðí ó " << maxMonth << "-ìó ì³ñÿö³." << endl;
    cout << "Ì³í³ìàëüíèé ïðèáóòîê: " << minProfit << " ãðí ó " << minMonth << "-ìó ì³ñÿö³." << endl;

    return 0;
}
