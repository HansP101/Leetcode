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
    int ans;
    int longestConsecutive(TreeNode* root) {
        DFShelper(root,root->val,0);
        return ans;
    }
    void DFShelper(TreeNode* node, int target, int subans){
        if(node==nullptr) return;
        if(node->val==target){
            subans+=1;
            ans=max(ans, subans);
        }
        else subans=1;
        DFShelper(node->left, node->val+1, subans);
        DFShelper(node->right, node->val+1, subans);
    }
};
