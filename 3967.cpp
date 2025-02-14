#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCut(const vector<long long>& ropes, long long length, int k) {
    int count = 0;
    for (long long rope : ropes) {
        count += rope / length;
    }
    return count >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<long long> ropes(n);
    long long max_length = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        max_length = max(max_length, ropes[i]);
    }
    
    long long left = 1, right = max_length, answer = 0;
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canCut(ropes, mid, k)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    cout << answer << endl;
    return 0;
}