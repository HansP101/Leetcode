/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans; 
    unordered_set<TreeNode*> visitedNode;
    
        void searchNode(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& childToParentMap, int k){
       if (node==nullptr) return;
       if(visitedNode.find(node)!=visitedNode.end())return;
        visitedNode.insert(node);
        if(k==0){
        ans.push_back(node->val);
        return;}
        if(node->left)
            searchNode(node->left, childToParentMap, k-1);
        if(node->right)
            searchNode(node->right, childToParentMap, k-1);
            TreeNode * parent=childToParentMap[node];
            if(parent) searchNode(parent, childToParentMap, k-1);
    }
    
      void fillupChildToParentMap(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& childToParentMap){
        if(node==nullptr) return;
        if(node->left){
            childToParentMap[node->left]=node;
            fillupChildToParentMap(node->left, childToParentMap);
        }
        if(node->right){
            childToParentMap[node->right]=node;
            fillupChildToParentMap(node->right, childToParentMap);
        }
    }
    
    TreeNode* findTargetNode(TreeNode *node, TreeNode* target){
        if(node==nullptr) return nullptr;
        if(node==target) return node;
        if(node->left){
            TreeNode* temp=findTargetNode(node->left, target);
            if(temp==target) return temp;}
        if(node->right){
            TreeNode* temp=findTargetNode(node->right, target);
            if(temp==target) return temp;}
        
             return node;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> childToParentMap;
        fillupChildToParentMap(root, childToParentMap);
        TreeNode* node=findTargetNode(root,target);
        searchNode(node, childToParentMap, k);
        return ans;
    }
};
