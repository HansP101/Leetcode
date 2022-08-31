/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root=p;
        while(root->parent){
            root=root->parent;
        }
        return LCA(root, p, q);
    }
    Node* LCA(Node* node, Node* p, Node* q){
        if(node==nullptr) return nullptr;
        if(node==p or node==q) return node;
        Node* l=LCA(node->left, p, q);
        Node* r=LCA(node->right, p, q);
        if(l and r) return node;
        return l? l:r;
    }
};
