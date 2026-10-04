#include <iostream>

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

    Node* findRec(Node* node, int val) {
        if (node == nullptr || node->data == val) {
            return node;
        }
        if (val < node->data) {
            return findRec(node->left, val);
        }
        return findRec(node->right, val);
    }

    int countSubtreeSize(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countSubtreeSize(node->left) + countSubtreeSize(node->right);
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

    int getSubtreeSize(int val) {
        Node* target = findRec(root, val);
        if (target == nullptr) {
            return 0;
        }
        return countSubtreeSize(target);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    BinarySearchTree bst;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bst.insert(x);
    }

    int x;
    cin >> x;

    cout << bst.getSubtreeSize(x) << "\n";

    return 0;
}