#include <iostream>
#include <algorithm>

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
    int max_diameter;

    int computeHeightAndDiameter(Node* node) {
        if (node == nullptr) return 0;
        
        int left_h = computeHeightAndDiameter(node->left);
        int right_h = computeHeightAndDiameter(node->right);

        int current_diameter = left_h + right_h + 1;
        if (current_diameter > max_diameter) {
            max_diameter = current_diameter;
        }

        return 1 + max(left_h, right_h);
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr), max_diameter(0) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }
    void insert(int val) {
        if (root == nullptr) {
            root = new Node(val);
            return;
        }
        Node* curr = root;
        while (true) {
            if (val == curr->data) {
                return;
            }
            if (val < curr->data) {
                if (curr->left == nullptr) {
                    curr->left = new Node(val);
                    break;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = new Node(val);
                    break;
                }
                curr = curr->right;
            }
        }
    }

    int getMaximumDistance() {
        max_diameter = 0;
        computeHeightAndDiameter(root);
        return max_diameter;
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

    cout << bst.getMaximumDistance() << "\n";

    return 0;
}