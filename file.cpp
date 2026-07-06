#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

// Функція для красивого виведення
void printMatrix(int matrix[4][5], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// 1 Сортування двовимірного масиву
void task1() {
    cout << endl << "ЗАВДАННЯ 1" << endl;
    int matrix[4][5];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 5; ++j) matrix[i][j] = rand() % 50;

    cout << "Початковий масив:" << endl;
    printMatrix(matrix, 4, 5);

    cout << "\nОберіть тип сортування:\n1 - За стовпцями\n2 - Всього масиву\nВаш вибір: ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        for (int j = 0; j < 5; ++j) {
            for (int i = 0; i < 4 - 1; ++i) {
                for (int k = 0; k < 4 - i - 1; ++k) {
                    if (matrix[k][j] > matrix[k + 1][j]) {
                        swap(matrix[k][j], matrix[k + 1][j]);
                    }
                }
            }
        }
        cout << "\nМасив після сортування за стовпцями:" << endl;
        printMatrix(matrix, 4, 5);
    }
    else if (choice == 2) {
        int* flat = &matrix[0][0];
        sort(flat, flat + 20);
        cout << "\nМасив після сортування повністю:" << endl;
        printMatrix(matrix, 4, 5);
    }
}

// 2 Суми по рядках та стовпцях
void task2() {
    cout << "\nЗАВДАННЯ 2" << endl;
    const int ROWS = 3;
    const int COLS = 4;
    int matrix[ROWS][COLS] = {
        {3, 5, 6, 7},
        {12, 1, 1, 1},
        {0, 7, 12, 1}
    };

    int rowSums[ROWS] = { 0 };
    int colSums[COLS] = { 0 };
    int totalSum = 0;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            rowSums[i] += matrix[i][j];
            colSums[j] += matrix[i][j];
            totalSum += matrix[i][j];
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) cout << setw(4) << matrix[i][j];
        cout << "  | " << setw(3) << rowSums[i] << endl;
    }
    cout << "------------------------" << endl;
    for (int j = 0; j < COLS; ++j) cout << setw(4) << colSums[j];
    cout << "  | " << setw(3) << totalSum << endl;
}

// 3 Масив 5х10 та масив 5х5
void task3() {
    cout << "\nЗАВДАННЯ 3" << endl;
    int m1[5][10];
    int m2[5][5];

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) m1[i][j] = rand() % 51;
    }

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m2[i][j] = m1[i][2 * j] + m1[i][2 * j + 1];
        }
    }

    cout << "Перший масив (5x10):" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) cout << setw(4) << m1[i][j];
        cout << endl;
    }

    cout << "\nДругий масив (5x5, суми сусідніх елементів першого):" << endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) cout << setw(4) << m2[i][j];
        cout << endl;
    }
}

// 4 Динамічний тривимірний маси
void task4() {
    cout << "\nЗАВДАННЯ 4" << endl;
    int d1, d2, d3;
    cout << "Введіть розміри тривимірного масиву (наприклад, 2 3 4): ";
    cin >> d1 >> d2 >> d3;

    int startValue;
    cout << "Введіть початкове число (наприклад, 3): ";
    cin >> startValue;

    int*** arr = new int** [d1];
    for (int i = 0; i < d1; ++i) {
        arr[i] = new int* [d2];
        for (int j = 0; j < d2; ++j) {
            arr[i][j] = new int[d3];
        }
    }

    int current = startValue;
    for (int i = 0; i < d1; ++i) {
        for (int j = 0; j < d2; ++j) {
            for (int k = 0; k < d3; ++k) {
                arr[i][j][k] = current++;
            }
        }
    }

    cout << "\nСтворений тривимірний масив:" << endl;
    for (int i = 0; i < d1; ++i) {
        cout << "Шар (вимір 1) " << i + 1 << " -" << endl;
        for (int j = 0; j < d2; ++j) {
            for (int k = 0; k < d3; ++k) {
                cout << setw(5) << arr[i][j][k];
            }
            cout << endl;
        }
    }

    for (int i = 0; i < d1; ++i) {
        for (int j = 0; j < d2; ++j) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    srand(time(0));

    task1();
    task2();
    task3();
    task4();

    return 0;
}
