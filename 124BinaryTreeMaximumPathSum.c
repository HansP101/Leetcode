/**

 Binary Tree Maximum Path Sum
 
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
    int maxPathSum(TreeNode* root) {
        ans=root->val;
        DFShelper(root);
        return ans;
    }
    
    int DFShelper(TreeNode *node){
        int l=0, r=0;
        if(node==nullptr) return 0;
        l=DFShelper(node->left);
        r=DFShelper(node->right);
        ans=max(ans, max(node->val,max(max(l,r)+node->val, l+r+node->val)));
        return max(max(l,r)+node->val, node->val);
    }
};
