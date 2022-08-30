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
    bool isCompleteTree(TreeNode* root) {
        bool balance=false;
        queue<TreeNode*> TreeQ;
        TreeQ.push(root);
        while(!TreeQ.empty()){
            auto qout=TreeQ.front();
            TreeQ.pop();
            if(qout==nullptr) {
                balance=true;
                continue;}
            if(balance) return false;
            TreeQ.push(qout->left);
            TreeQ.push(qout->right);
        }
        return true;
    }
};
