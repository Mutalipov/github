#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<long long> prefix_sums(n);
    long long current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        long long lines;
        cin >> lines;
        current_sum += lines;
        prefix_sums[i] = current_sum; 
    }

    for (int i = 0; i < m; i++) {
        long long mistake_line;
        cin >> mistake_line;

        auto it = lower_bound(prefix_sums.begin(), prefix_sums.end(), mistake_line);
        
        int block_number = distance(prefix_sums.begin(), it) + 1;
        
        cout << block_number << "\n";
    }
    return 0;
}