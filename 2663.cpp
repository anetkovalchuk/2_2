#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int>& arr) {
    int n = arr.size();
    int swap_count = 0;
    bool swapped;
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap_count++;
                swapped = true;
            }
        }
        if (!swapped) break; // Якщо не було жодного обміну, завершити сортування
    }
    
    return swap_count;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int result = bubbleSort(arr);
    cout << result << endl;
    
    return 0;
}
