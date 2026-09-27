#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sheep {
    long long x2, y2;
};

struct FenwickTree {
    int size;
    vector<int> tree;
    FenwickTree(int n) : size(n), tree(n + 1, 0) {}
    void add(int i, int delta) {
        for (++i; i <= size; i += i & -i) tree[i] += delta;
    }
    int query(int i) {
        int sum = 0;
        for (++i; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long K;
    if (!(cin >> n >> K)) return 0;

    vector<Sheep> sheeps(n);
    vector<long long> y_coords;
    long long max_coord = 0;

    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sheeps[i] = {x2, y2};
        y_coords.push_back(y2);
        max_coord = max({max_coord, x2, y2});
    }

    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());

    sort(sheeps.begin(), sheeps.end(), [](const Sheep& a, const Sheep& b) {
        return a.x2 < b.x2;
    });

    long long low = 1, high = max_coord;
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        FenwickTree ft(y_coords.size());
        
        for (const auto& s : sheeps) {
            if (s.x2 > mid) break;
            int y_idx = lower_bound(y_coords.begin(), y_coords.end(), s.y2) - y_coords.begin();
            ft.add(y_idx, 1);
        }

        int y_limit_idx = upper_bound(y_coords.begin(), y_coords.end(), mid) - y_coords.begin() - 1;
        
        long long count = 0;
        if (y_limit_idx >= 0) {
            count = ft.query(y_limit_idx);
        }

        if (count >= K) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}