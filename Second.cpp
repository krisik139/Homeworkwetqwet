#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("chcp 1251>null");
    srand(time(0));

    int profit[12];
    cout << "ѕрибуток ф≥рми за 12 м≥с€ц≥в: " << endl;
    for (int i = 0; i < 12; i++) {
        profit[i] = rand() % 90000 + 10000;
        cout << i + 1 << " м≥с: " << profit[i] << " грн." << endl;
    }

    int start;
    int end;
    cout << "\n¬вед≥ть початковий м≥с€ць д≥апазону (1-12): ";
    cin >> start;
    cout << "¬вед≥ть к≥нцевий м≥с€ць д≥апазону (1-12): ";
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

    cout << "\n” д≥апазон≥ в≥д " << start << " до " << end << " м≥с€ц€:" << endl;
    cout << "ћаксимальний прибуток: " << maxProfit << " грн у " << maxMonth << "-му м≥с€ц≥." << endl;
    cout << "ћ≥н≥мальний прибуток: " << minProfit << " грн у " << minMonth << "-му м≥с€ц≥." << endl;

    return 0;
}