#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>


void task1() {
    std::cout << "\nЗАВДАННЯ 1" << std::endl;

    std::string* surnames = new std::string[5];

    std::cout << "Введіть 5 прізвищ студентів:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Прізвище " << i + 1 << ": ";
        std::cin >> surnames[i];
    }

    for (int i = 0; i < 5 - 1; ++i) {
        for (int j = 0; j < 5 - i - 1; ++j) {
            if (surnames[j] > surnames[j + 1]) {
                swap(surnames[j], surnames[j + 1]);
            }
        }
    }

    std::cout << "\nВідсортовані прізвища:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << surnames[i] << std::endl;
    }

    delete[] surnames;
}

void task2() {
    std::cout << "\nЗАВДАННЯ 2" << std::endl;
    int rows = 5;
    int cols = 5;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 6;
        }
    }

    std::cout << "Початкова матриця:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) std::cout << std::setw(4) << matrix[i][j];
        std::cout << std::endl;
    }

    int newRowsCount = 0;
    for (int i = 0; i < rows; ++i) {
        bool hasZero = false;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (!hasZero) newRowsCount++;
    }

    int** newMatrix = new int* [newRowsCount];
    int currentNewRow = 0;

    for (int i = 0; i < rows; ++i) {
        bool hasZero = false;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                hasZero = true;
                break;
            }
        }

        if (!hasZero) {
            newMatrix[currentNewRow] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                newMatrix[currentNewRow][j] = matrix[i][j];
            }
            currentNewRow++;
        }
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;

    std::cout << "\nМатриця після видалення рядків з нулями:" << std::endl;
    if (newRowsCount == 0) {
        std::cout << "[Усі рядки містили нулі, матриця порожня]" << std::endl;
    }
    else {
        for (int i = 0; i < newRowsCount; ++i) {
            for (int j = 0; j < cols; ++j) std::cout << std::setw(4) << newMatrix[i][j];
            std::cout << std::endl;
        }
    }

    // Очищаємо нову матрицю
    for (int i = 0; i < newRowsCount; ++i) {
        delete[] newMatrix[i];
    }
    delete[] newMatrix;
}

void addColumn(int**& matrix, int rows, int& cols, int pos) {
    int** newMatrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        newMatrix[i] = new int[cols + 1];
    }

    for (int i = 0; i < rows; ++i) {
        int newJ = 0;
        for (int j = 0; j < cols; ++j) {
            if (j == pos) {
                newMatrix[i][newJ] = 99;
                newJ++;
            }
            newMatrix[i][newJ] = matrix[i][j];
            newJ++;
        }
        if (pos == cols) {
            newMatrix[i][cols] = 99;
        }
    }

    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;

    matrix = newMatrix;
    cols++;
}

void task3() {
    std::cout << "\nЗАВДАННЯ 3" << std::endl;
    int rows = 3, cols = 4;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    // Заповнення
    int counter = 10;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) matrix[i][j] = counter++;
    }

    std::cout << "Початкова матриця:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) std::cout << std::setw(4) << matrix[i][j];
        std::cout << std::endl;
    }

    int pos;
    std::cout << "\nВведіть позицію (від 0 до " << cols << ") для вставки стовпця: ";
    std::cin >> pos;

    if (pos >= 0 && pos <= cols) {
        addColumn(matrix, rows, cols, pos);

        std::cout << "\nМатриця після вставки стовпчика:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) std::cout << std::setw(4) << matrix[i][j];
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Некоректна позиція!" << std::endl;
    }

    // Фінальне очищення
    for (int i = 0; i < rows; ++i) delete[] matrix[i];
    delete[] matrix;
}

int main() {
    system("chcp 1251>null");
    srand(time(0));

    task1();
    task2();
    task3();

    std::cout << "\nСвобода! Всі завдання повністю готові!" << std::endl;
    return 0;
}
