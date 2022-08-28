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

struct NodeVal{
    int left; 
    int right;
    TreeNode* node;
};
class Solution {
public:
    map<int,vector<NodeVal>> colToNode;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<NodeVal> NodeQ;
        NodeQ.push({0, 0, root});
        while(!NodeQ.empty()){
            auto qout=NodeQ.front();
            NodeQ.pop();
            colToNode[qout.right].push_back(qout);
            if(qout.node->left) NodeQ.push({qout.left+1, qout.right-1, qout.node->left});
            if(qout.node->right) NodeQ.push({qout.left+1, qout.right+1, qout.node->right});
        }
        for(auto it: colToNode){
            vector<int> temp;
            sort(it.second.begin(), it.second.end(), [](auto &a, auto&b){return a.left==b.left? a.node->val<b.node->val: a.left<b.left;});
            for(auto it2: it.second){
                temp.push_back(it2.node->val);
                }
            ans.push_back(temp);
    }
        return ans;
    }
};
