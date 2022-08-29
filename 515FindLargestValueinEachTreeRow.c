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
/* DFS solution
class Solution {
public:
    vector<int>ans;
    vector<int> largestValues(TreeNode* root) {
       DFShelper(root, 0);
        return ans;
    }
    void DFShelper(TreeNode* node, int depth){
        if(node==nullptr) return;
        if(ans.size()==depth){
            ans.push_back(node->val);
        }else
            if(ans[depth]<node->val) ans[depth]=node->val;
        DFShelper(node->left, depth+1);
        DFShelper(node->right, depth+1);
    }
};
*/
//BFS solution
class Solution {
public:
    vector<int>ans;
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> TreeQ;
        if (root==nullptr) return ans;
        TreeQ.push(root);
        while(!TreeQ.empty()){
            int temp=INT_MIN;
            int TreeQsize=TreeQ.size();
            for(int i=0; i<TreeQsize; i++){
                auto qout=TreeQ.front();
                TreeQ.pop();
                if (qout->val > temp) temp=qout->val;
                if(qout->left)TreeQ.push(qout->left);
                if(qout->right)TreeQ.push(qout->right);
            }
            ans.push_back(temp);
    }
        return ans;
    }
};
