#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    int id;
    int depth;
    Node* left;
    Node* right;
    Node(int v, int i, int d) : val(v), id(i), depth(d), left(nullptr), right(nullptr) {}
};

struct NodeInfo {
    int val;
    int id;
    Node* nodePtr;

    bool operator<(const NodeInfo& other) const {
        if (val != other.val) return val < other.val;
        return id > other.id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<NodeInfo> active_nodes;
    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int val = a[i];
        NodeInfo query = {val, i, nullptr};
        auto it = active_nodes.lower_bound(query);

        Node* pred = nullptr;
        Node* succ = nullptr;

        if (it != active_nodes.end()) {
            succ = it->nodePtr;
        }
        if (it != active_nodes.begin()) {
            pred = prev(it)->nodePtr;
        }

        Node* newNode = nullptr;
        if (!pred && !succ) {
            newNode = new Node(val, i, 0);
            root = newNode;
        } else if (pred && !succ) {
            newNode = new Node(val, i, pred->depth + 1);
            pred->right = newNode;
        } else if (!pred && succ) {
            newNode = new Node(val, i, succ->depth + 1);
            succ->left = newNode;
        } else {
            if (pred->depth > succ->depth) {
                newNode = new Node(val, i, pred->depth + 1);
                pred->right = newNode;
            } else {
                newNode = new Node(val, i, succ->depth + 1);
                succ->left = newNode;
            }
        }

        active_nodes.insert({val, i, newNode});
    }

    for (int i = 0; i < m; i++) {
        string p;
        cin >> p;
        Node* curr = root;
        bool possible = true;
        for (char ch : p) {
            if (!curr) {
                possible = false;
                break;
            }
            if (ch == 'L') {
                curr = curr->left;
            } else if (ch == 'R') {
                curr = curr->right;
            }
        }
        if (curr && possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}