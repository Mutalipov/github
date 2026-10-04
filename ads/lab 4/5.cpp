#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Node*> nodes(n + 1);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 0) {
            nodes[x]->left = nodes[y];
        } else {
            nodes[x]->right = nodes[y];
        }
    }

    queue<Node*> q;
    q.push(nodes[1]);
    int max_width = 0;

    while (!q.empty()) {
        int level_size = q.size();
        max_width = max(max_width, level_size);

        for (int i = 0; i < level_size; i++) {
            Node* curr = q.front();
            q.pop();

            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }

    cout << max_width << "\n";

    for (int i = 1; i <= n; i++) {
        delete nodes[i];
    }

    return 0;
}