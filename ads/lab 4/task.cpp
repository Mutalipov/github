#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST{
private:
    Node* root;

    Node* insertRec(Node* node, int val) {
        if (node == nullptr){
            return new Node(val);
        }
        if(val<node->data){
            node->left = insertRec(node->left, val);
        }
        else if(val>node->data){
            node->right = insertRec(node->right, val);
        }
        return node;
    }
    int counting(Node* node){
        if(node == nullptr) return 0;
        int current_match = 0;
        if((node->left != nullptr && node->right==nullptr) ||(node->left == nullptr && node->right !=nullptr)){
            current_match = 1;
        }
        return current_match + counting(node->left) + counting(node->right);
    }

    void destroy(Node* node){
        if(node!= nullptr){
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
public:
    BST() : root(nullptr){}
    ~BST() {
        destroy(root);
    }

    void insert(int val){
        root = insertRec(root, val);
    }
    int getcount(){
        return counting(root);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    BST bst;
    for(int i = 0; i<n;i++){
        int x;
        cin>>x;
        bst.insert(x);
    }

    cout<<bst.getcount()<<"\n";
}
