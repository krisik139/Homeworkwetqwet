#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string surname;
    string group;
    int grades[5];
};

void addStudent(Student*& arr, int& size, const Student& s) {
    Student* newArr = new Student[size + 1];
    for (int i = 0; i < size; ++i) {
        newArr[i] = arr[i];
    }
    newArr[size] = s;
    size++;
    delete[] arr;
    arr = newArr;
}

// я ще тут зробив ЗАВДАННЯ 2
struct Date { 
    int day;
    int month;
    int year;
};
struct Man {
    string surname;
    string name;
    int age;
    Date birth; };

void printMan(const Man& m) {
    cout << m.surname << " " << m.name << ", " << m.age << " р.в. (Нар: " << m.birth.day << "." << m.birth.month << ")\n";
}

int main() {
    system("chcp 1251>null");

    cout << "ЗАВДАННЯ 1" << endl;
    int size = 0;
    Student* students = nullptr;

    addStudent(students, size, { "Іванов", "КН", {5, 5, 5, 5, 4} });
    addStudent(students, size, { "Петров", "КН", {2, 3, 2, 5, 3} });

    cout << "Відмінники (>75% 5): ";
    for (int i = 0; i < size; ++i) {
        if (count(students[i].grades, students[i].grades + 5, 5) >= 4) cout << students[i].surname << " ";
    }
    cout << "\nДвієчники (>50% 2/3): ";
    for (int i = 0; i < size; ++i) {
        int bad = count_if(students[i].grades, students[i].grades + 5, [](int g) { return g == 2 || g == 3; });
        if (bad >= 3) cout << students[i].surname << " ";
    }
    delete[] students;

    cout << endl << endl << "ЗАВДАННЯ 2" << endl;
    vector<Man> people = {
        {"Шевченко", "Тарас", 45, {10, 3, 1981}},
        {"Франко", "Іван", 32, {27, 8, 1994}},
        {"Костенко", "Ліна", 40, {19, 3, 1986}}
    };

    people.push_back({ "Леся", "Українка", 28, {25, 2, 1998} });
    people.erase(people.begin() + 1);

    people[0].age = 46;

    sort(people.begin(), people.end(), [](const Man& a, const Man& b) { return a.surname < b.surname; });
    cout << "Відсортований список після змін:\n";
    for (const auto& m : people) printMan(m);

    cout << "\nПошук (Ліна Костенко): ";
    auto it = find_if(people.begin(), people.end(), [](const Man& m) { return m.surname == "Костенко" && m.name == "Ліна"; });
    if (it != people.end()) printMan(*it);

    cout << "\nІменинники березня (місяць 3):\n";
    for (const auto& m : people) {
        if (m.birth.month == 3) printMan(m);
    }

    return 0;
}
