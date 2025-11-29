#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    int a[100]; 

    cout << "Введіть " << n << " елементів масиву:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1. Піднести кожен елемент до кубу
    for (int i = 0; i < n; i++) {
        a[i] = a[i] * a[i] * a[i];   
    }

    // 2. Сортування методом обміну (bubble sort) за спаданням
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] < a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // 3. Вивести відсортований масив
    cout << "\nМасив після піднесення до кубу та сортування за спаданням:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
