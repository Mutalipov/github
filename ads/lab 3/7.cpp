#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;
    vector<double> a(n);
    double max_len = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_len = max(max_len, a[i]);
    }
    double low = 0, high = max_len;
    for (int iter = 0; iter < 80; ++iter) {
        double mid = low + (high - low) / 2;      
        long long total_pieces = 0;
        for (int i = 0; i < n; ++i) {
            if (mid > 0) {
                total_pieces += (long long)(a[i] / mid);
            }
        }
        if (total_pieces >= k) {
            low = mid; 
        } else {
            high = mid;   
        }
    }
    cout << fixed << setprecision(7) << low << "\n";
}