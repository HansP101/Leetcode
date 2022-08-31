class Solution{
public:
    vector<vector<int>> output;
    vector<vector<int>> verticalOrder(TreeNode* root){
        map<int, vector<int>> mapColumnNodes; // K:column index, v:Node val arrays
        queue<pair<int, TreeNode*>>ColumnQueue;
    	if(root==nullptr) return output;
        ColumnQueue.push(make_pair(0,root));
        while(!ColumnQueue.empty()){
                auto qout=ColumnQueue.front();
                ColumnQueue.pop();
                mapColumnNodes[qout.first].push_back(qout.second->val);
                if(qout.second->left)ColumnQueue.push(make_pair(qout.first-1,qout.second->left));
                if(qout.second->right)ColumnQueue.push(make_pair(qout.first+1,qout.second->right));
            }
         for(auto it: mapColumnNodes){
            output.push_back(it.second);
        }
    return output;
    }
} ;

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
struct TreeSet{
    int row;
    int val;
};

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<TreeSet>> treeMap; //k:col, v: TreeSet
        fillupTreeMap(root, 0, 0, treeMap);
        for(auto it: treeMap){
            sort(it.second.begin(), it.second.end(), [](auto &a, auto &b){return a.row<b.row;});
            vector<int> temp;
            for(auto it2: it.second){
                temp.push_back(it2.val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    void fillupTreeMap(TreeNode* node, int row, int col, map<int, vector<TreeSet>>& treeMap){
        if (node==nullptr) return;
        treeMap[col].push_back({row, node->val});
        fillupTreeMap(node->left, row+1, col-1, treeMap);
        fillupTreeMap(node->right, row+1, col+1, treeMap);
    }
};
