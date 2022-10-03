

class Solution {
public:   
    vector<int>ret;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root!=NULL) {
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
        }
        return ret;
    }
};
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        stack<TreeNode*> stk;
        TreeNode* curr=root;
        
        while(curr || !stk.empty()){
            while(curr){
                stk.push(curr);
                curr=curr->left;
            }
            curr=stk.top();
            output.push_back(curr->val);
            stk.pop();
            if(curr)
                curr=curr->right;
                
        }
        return output;
        
    }
};
