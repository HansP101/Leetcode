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
    vector<vector<int>> levelOrder(TreeNode* root) {
     vector<vector<int>> ans;
        queue<TreeNode*> TreeQ;
        if (root==nullptr) return ans;
        TreeQ.push(root);
        while(!TreeQ.empty()){
            vector<int> levelVal;
            int Qsize=TreeQ.size();
            for(int i=0; i<Qsize;i++){
                TreeNode* temp=TreeQ.front();
                TreeQ.pop();
                levelVal.push_back(temp->val);
                if(temp->left){     
                    TreeQ.push(temp->left);
                }
                if(temp->right){
                    TreeQ.push(temp->right);
                }
             }
            ans.push_back(levelVal);
            }
        return ans;
    }
};
