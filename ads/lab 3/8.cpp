#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long S;
    if (!(cin >> n >> S)) return 0;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int left = 0;
    long long current_sum = 0;
    int min_len = n + 1;
    
    for (int right = 0; right < n; right++) {
        current_sum += arr[right];
        while (left <= right && current_sum >= S) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
            }
            current_sum -= arr[left];
            left++;
        }
    }
    
    if (min_len > n) {
        cout << 0 << "\n"; 
    } else {
        cout << min_len << "\n";
    }
    
    return 0;
}