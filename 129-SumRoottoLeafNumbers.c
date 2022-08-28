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

    int sumNumbers(TreeNode* root) {
       int ans=0;
        DFShelper(root, 0, ans);
        return ans;
    }
    
    void DFShelper(TreeNode* node, int subsum, int &ans){
        if(!node->left and !node->right) ans+=subsum*10+node->val;
        if(node->left) DFShelper(node->left, subsum*10+node->val, ans);
        if(node->right) DFShelper(node->right, subsum*10+node->val, ans);
    }
};

class Solution {
 public:
    int ans=0;
	int sumNumbers(TreeNode* root){
		DFShelper(root,root->val);
        return ans;
	}
	void DFShelper(TreeNode* node, int subSum){
	 	if(!node->left and !node->right) ans+=subSum;
		else {
            if(node->left)DFShelper(node->left, subSum*10+node->left->val);
		    if(node->right)DFShelper(node->right, subSum*10+node->right->val);
	    }
    }
};
