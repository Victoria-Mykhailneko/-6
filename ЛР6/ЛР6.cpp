#include <iostream>
#include <vector>
#include <cmath>    
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cout << "Введіть кількість елементів n: ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Невірне значення n\n";
        return 1;
    }

    vector<long long> a(n);
    cout << "Введіть " << n << " цілих(і) елемент(ів) масиву, розділених пробілами або Enter:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 1) Піднести кожен елемент до кубу.
    for (int i = 0; i < n; ++i) {
        long long x = a[i];
        a[i] = x * x * x; // еквівалент pow(x,3) але точніше і швидше для цілих
    }

    // 2) Сортування методом обміну (bubble sort) за спаданням
    bool swapped = true;
    for (int pass = 0; pass < n - 1 && swapped; ++pass) {
        swapped = false;
        for (int j = 0; j < n - 1 - pass; ++j) {
            if (a[j] < a[j + 1]) {         
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
    }

    // 3) Вивід відсортованого масиву
    cout << "Відсортований за спаданням масив після піднесення до кубу:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i + 1 < n ? ' ' : '\n');
    }

    return 0;
}
