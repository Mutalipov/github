#include <iostream>
#include <vector>
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
    long long current_sum;

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

    void transformRec(Node* node) {
        if (node == nullptr) return;

        transformRec(node->right);  
        
        current_sum += node->data;  
        node->data = current_sum;  
        
        transformRec(node->left);   
    }

    void collectRec(Node* node, vector<int>& vals) {
        if (node == nullptr) return;
        collectRec(node->left, vals);
        vals.push_back(node->data);
        collectRec(node->right, vals);
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr), current_sum(0) {}

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int val) {
        root = insertRec(root, val);
    }

    void transform() {
        current_sum = 0;
        transformRec(root);
    }

    vector<int> getValues() {
        vector<int> vals;
        collectRec(root, vals);
        return vals;
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

    bst.transform();

    vector<int> result = bst.getValues();
    sort(result.begin(), result.end());

    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}