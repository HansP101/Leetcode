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
    struct TreeDepth{
        int depth;
        TreeNode* node;
    };
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeDepth> TreeQ;
        if (root==nullptr) return ans;
        TreeQ.push({0,root});
        map<int, vector<int>>TreeMap; //K:depth, V:node->val
        while(!TreeQ.empty()){
            auto qout=TreeQ.front();
            TreeQ.pop();
            TreeMap[qout.depth].push_back(qout.node->val);
            if(qout.node->right) TreeQ.push({qout.depth+1, qout.node->right});
             if(qout.node->left) TreeQ.push({qout.depth+1, qout.node->left});
        }
        for(auto it: TreeMap){
            ans.push_back(it.second[0]);
            }
        return ans;
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        DFS(root, 0, view);
        return view;
    }
    void DFS(TreeNode* root, int depth, vector<int>&view){
        if (root==nullptr) return;
        if(depth==view.size()) view.push_back(root->val);
        if(root->right) DFS(root->right, depth+1, view);
        if(root->left) DFS(root->left, depth+1, view);
    }
};
