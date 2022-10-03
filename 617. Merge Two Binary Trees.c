class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1&& !root2)
            return NULL;
        if(root1&&!root2)
            return root1;
        if(!root1&&root2)
            return root2;
        TreeNode* ansTree= new TreeNode(root1->val+root2->val);
        ansTree->left=mergeTrees(root1->left, root2->left);
         ansTree->right=mergeTrees(root1->right, root2->right);
        return ansTree;
    }
};
