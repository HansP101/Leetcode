/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans=0;
    int diameter(Node* root) {
        DFShelper(root);
        return ans;
    }
    int DFShelper(Node* node){
        int longest=0, second=0; //longest path length in current node
        if(node==nullptr) return 0;
        for(auto it: node->children){
            int temp=DFShelper(it);
            if(temp>longest){
                second=longest;
                longest=temp;
                }
            else if(temp>second) second=temp;
        }
        ans=max(ans, longest+second);
        return longest+1;
    }
};
