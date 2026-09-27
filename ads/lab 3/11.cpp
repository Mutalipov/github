#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    vector<long long> queries(t);
    for (int i = 0; i < t; i++) {
        cin >> queries[i];
    }

    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int q = 0; q < t; q++) {
        long long val = queries[q];
        int ans_r = -1, ans_c = -1;
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                auto it = lower_bound(a[i].begin(), a[i].end(), val, greater<long long>());
                if (it != a[i].end() && *it == val) {
                    ans_r = i;
                    ans_c = distance(a[i].begin(), it);
                    found = true;
                    break;
                }
            } else {
                auto it = lower_bound(a[i].begin(), a[i].end(), val);
                if (it != a[i].end() && *it == val) {
                    ans_r = i;
                    ans_c = distance(a[i].begin(), it);
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << ans_r << " " << ans_c << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    return 0;
}