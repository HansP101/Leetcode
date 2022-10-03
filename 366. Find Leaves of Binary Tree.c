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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        while(root){
            vector<int> array;
            helper_DFS(array, root);
            ans.push_back(array);
        }
        return ans;
    }
    void helper_DFS(vector<int> &array, TreeNode* &root){
        if((!root->left) and (!root->right)){
            array.push_back(root->val);
            root=nullptr;
        }
        else{
            if(root->left)
                helper_DFS(array, root->left);
            if(root->right)
                helper_DFS(array, root->right);
        }
    }
};

