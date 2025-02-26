#include <iostream>
#include <vector>
#include <string>

using namespace std;

void selectionSort(vector<string>& words) {
    int n = words.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (words[j] < words[minIndex]) {
                minIndex = j;
            }
        }
        swap(words[i], words[minIndex]);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    
    selectionSort(words);
    
    for (const string& word : words) {
        cout << word << endl;
    }
    
    return 0;
}
