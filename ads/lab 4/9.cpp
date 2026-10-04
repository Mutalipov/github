#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertRec(node->left, val);
        } else if (val > node->data) {
            node->right = insertRec(node->right, val);
        }
        return node;
    }

    int countLeavesRec(Node* node) {
        if (node == NULL) return 0;
        
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        
        return countLeavesRec(node->left) + countLeavesRec(node->right);
    }

    void destroyTree(Node* node) {
        if (node != NULL) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(NULL) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    int getLeafCount() {
        return countLeavesRec(root);
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

    cout << bst.getLeafCount() << "\n";

    return 0;
}