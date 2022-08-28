/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
        DFShelper(root);
        return ans;
    }
    
    int DFShelper(TreeNode* node){
        int l=0,r=0;
        if(node==nullptr) return 0;
        l=DFShelper(node->left);
        r=DFShelper(node->right);
        ans=max(ans, l+r);
        return max(l, r)+1;
    }
};
