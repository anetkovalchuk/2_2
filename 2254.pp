#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функція для підрахунку кількості рисових полів, які можна обробити в межах бюджету B
int countRiceFields(const vector<int>& fields, int storage_pos, int B) {
    int cost = 0, count = 0;
    for (int x : fields) {
        cost += abs(x - storage_pos);
        if (cost > B) break;
        count++;
    }
    return count;
}

int main() {
    int R, L, B;
    cin >> R >> L >> B;
    
    vector<int> fields(R);
    for (int i = 0; i < R; i++) {
        cin >> fields[i];
    }
    
    sort(fields.begin(), fields.end()); // Сортуємо поля за зростанням
    
    int left = fields[0], right = fields[R - 1];
    int max_rice = 0, best_storage = fields[0];
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int rice_count = 0, cost = 0;
        
        for (int i = 0; i < R; i++) {
            cost += abs(fields[i] - mid);
            if (cost > B) break;
            rice_count++;
        }
        
        if (rice_count > max_rice) {
            max_rice = rice_count;
            best_storage = mid;
        }
        
        if (cost <= B) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << max_rice << endl;
    return 0;
}