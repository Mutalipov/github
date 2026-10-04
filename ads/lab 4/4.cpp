#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    void getLevelSums(vector<long long>& sums) {
        if (root == nullptr) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            long long current_sum = 0;

            for (int i = 0; i < level_size; i++) {
                Node* curr = q.front();
                q.pop();

                current_sum += curr->data;

                if (curr->left != nullptr) {
                    q.push(curr->left);
                }
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }
            sums.push_back(current_sum);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    BinarySearchTree bst;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst.insert(x);
    }

    vector<long long> level_sums;
    bst.getLevelSums(level_sums);

    cout << level_sums.size() << "\n";

    for (size_t i = 0; i < level_sums.size(); i++) {
        cout << level_sums[i] << (i == level_sums.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}