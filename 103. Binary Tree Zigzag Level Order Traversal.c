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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root==nullptr) return ans;
        queue<TreeNode*> levelQ;
        levelQ.push(root);
        bool flag=false;
        while(!levelQ.empty()){
            int n=levelQ.size();
            vector<int> temp;
            for(; n>0; n--){
                auto it=levelQ.front();
                levelQ.pop();
                if(it->left) levelQ.push(it->left);
                if(it->right)levelQ.push(it->right);
                temp.push_back(it->val);
            }
            if(flag)reverse(temp.begin(), temp.end());
             ans.push_back(temp);
            flag=!flag;
        }
        return ans;
        
    }
};
