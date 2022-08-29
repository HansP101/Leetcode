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
    double min=INT_MAX;
    int closestValue(TreeNode* root, double target) {
        int ans=INT_MAX;
        DFShelper(root, target, ans);
        return ans;
    }
    void DFShelper(TreeNode *node, double target, int& ans){
        if(node==nullptr) return;
        double temp=abs(node->val-target);
        if(min>temp){
            ans=node->val;
            min=temp;}
        if(node->val >target) DFShelper(node->left, target, ans);
        else DFShelper(node->right, target, ans);
        
    }
};
