#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insertRec(Node* node, int val){
        if (node== nullptr){
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
    bool searchRec(Node* node, int val){
        if(node == nullptr) return false;
        if(node->data == val) return true;
        if(val<node->data){
            return searchRec(node->left, val);
        }
        return searchRec(node->right, val);
    }
    void inorderRec(Node* node){
        if(node!=nullptr){
            inorderRec(node->left);
            cout<<node->data<<" ";
            inorderRec(node->right);
        }
    }
    bool getAtIndexRec(Node* node, int targetindex, int& currentIndex, int& result){
        if(node == nullptr) return false;
        if(getAtIndexRec(node->left, targetindex, currentIndex, result)) return true;
        if(currentIndex == targetindex){
            result = node->data;
            return true;
        }
        currentIndex++;
        return getAtIndexRec(node->right, targetindex, currentIndex, result);
    }
    void destroyTree(Node* node){
        if( node!= nullptr){
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
public:
    BinarySearchTree():root(nullptr){}
    ~BinarySearchTree(){
        destroyTree(root);
    }
    void insert(int val){
        root = insertRec(root, val);
    }
    bool search(int val){
        return searchRec(root,val);
    }
    void inorder(){
        inorderRec(root);
        cout<<endl;
    }
    bool getElementAtIndex(int index, int& result){
        int currentIndex = 1;
        return getAtIndexRec(root, index, currentIndex, result);
    }
};

int main(){
    BinarySearchTree bst;
    int n, m; 
    cin>>n>>m;
    for(int i = 0; i<n;i++){
        int x;
        cin>>x;
        bst.insert(x);
    }
    int resultVal = 0;
    if(bst.getElementAtIndex(m,resultVal)){
        cout<<resultVal;
    }
    else cout<<-1;
}