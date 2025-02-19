#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_set<string> phonebook;

    for (int i = 0; i < N; i++) {
        string phone;
        cin >> phone;
        phonebook.insert(phone);  // Вставляємо номер у множину (унікальні значення)
    }

    cout << phonebook.size() << endl;  // Виводимо кількість унікальних записів

    return 0;
}
