#include <iostream>

int main() {
    int A[7] = { 1, 2, 3, 4, 5, 6, 7 };
    int B[7] = { 8, 9, 10, 11, 12, 13, 14 };

    int size = 14;
    int* C = new int[size];

    int* vkazC = C;

    for (int i = 0; i < 7; ++i) {
        *vkazC = A[i];
        vkazC++;
    }

    for (int i = 0; i < 7; ++i) {
        *vkazC = B[i];
        vkazC++;
    }

    std::cout << "Array C: ";
    for (int i = 0; i < size; ++i) {
        std::cout << *(C + i) << " ";
    }
    std::cout << std::endl;

    delete[] C;
    return 0;
}