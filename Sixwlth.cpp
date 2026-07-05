#include <iostream>

bool est(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (*(arr + i) == value) return true;
    }
    return false;
}

int main() {
    int A[7] = {1, 2, 3, 4, 5, 2, 7};
    int B[7] = {2, 7, 7, 8, 9, 3, 10};

    int zbigi[7];
    int count = 0;

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (A[i] == B[j]) {
                if (!est(zbigi, count, A[i])) {
                    *(zbigi + count) = A[i];
                    count++;
                }
            }
        }
    }

    int* C = new int[count];
    for (int i = 0; i < count; ++i) {
        *(C + i) = *(zbigi + i);
    }

    std::cout << "масив: ";
    for (int i = 0; i < count; ++i) {
        std::cout << *(C + i) << " ";
    }
    std::cout << std::endl;

    delete[] C;
    return 0;
}
