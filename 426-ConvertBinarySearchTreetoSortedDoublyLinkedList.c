/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head=nullptr;
    Node* last=nullptr;
    Node* treeToDoublyList(Node* root) {
        if(root==nullptr) return root;
         DFShelper(root);
        head->left=last;
        last->right=head;
        return head;
    }
    
    void DFShelper(Node* node){
        if(node==nullptr) return;
        DFShelper(node->left);
        if(head==nullptr){
            head=node;
        }
        else{
            last->right=node;
            node->left=last;
        }
        last=node;
         DFShelper(node->right);
        }
};
