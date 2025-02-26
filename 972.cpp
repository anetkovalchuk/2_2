#include <iostream>
#include <vector>

using namespace std;

// Структура для представлення моменту часу
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Функція для сортування вставками
void insertionSort(vector<Time>& times) {
    int n = times.size();
    for (int i = 1; i < n; i++) {
        Time key = times[i];
        int j = i - 1;

        // Порівнюємо моменти часу, щоб знайти правильне місце для вставки
        while (j >= 0 && (times[j].hours > key.hours ||
                         (times[j].hours == key.hours && times[j].minutes > key.minutes) ||
                         (times[j].hours == key.hours && times[j].minutes == key.minutes && times[j].seconds > key.seconds))) {
            times[j + 1] = times[j];
            j--;
        }
        times[j + 1] = key;
    }
}

int main() {
    int n;
    cin >> n;
    vector<Time> times(n);

    // Зчитуємо моменти часу
    for (int i = 0; i < n; i++) {
        cin >> times[i].hours >> times[i].minutes >> times[i].seconds;
    }

    // Сортуємо моменти часу за допомогою сортування вставками
    insertionSort(times);

    // Виводимо відсортовані моменти часу
    for (const auto& time : times) {
        cout << time.hours << " " << time.minutes << " " << time.seconds << endl;
    }

    return 0;
}
