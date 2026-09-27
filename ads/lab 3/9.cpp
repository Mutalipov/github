#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<long long> a(n);
    long long max_val = 0;
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
        total_sum += a[i];
    }
    long long low = max_val, high = total_sum;
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long blocks_needed = 1;
        long long current_block_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (current_block_sum + a[i] > mid) {
                blocks_needed++;
                current_block_sum = a[i];
            } else {
                current_block_sum += a[i];
            }
        }
        if (blocks_needed <= k) {
            ans = mid;      
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }
    cout << ans << "\n";
    return 0;
}