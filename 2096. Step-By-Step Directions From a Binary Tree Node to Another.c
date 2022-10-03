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
    /*
 1. find LCA--> Root
 2. LCA to Start node: all routes to 'U'
 3. LCA to End node and sum both 2 and 3. 
    
    
    */
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA_Root=findLCA(root, startValue, destValue);
        string p1, p2;
        getPath(LCA_Root, startValue, p1);//string 이름 자체가 포인터
        getPath(LCA_Root, destValue, p2);
        for(auto &c : p1) c = 'U';
        return p1 + p2;
        
    }
    
    TreeNode* findLCA(TreeNode* root, int startValue, int destValue){
        if(root==nullptr)
            return nullptr;
        if(root->val==startValue or root->val==destValue)
            return root;
        TreeNode* l=findLCA(root->left, startValue, destValue);
        TreeNode* r=findLCA(root->right, startValue, destValue);
        if(l and r) return root;
        return l? l:r;
    }
    
    bool getPath(TreeNode* root, int Value, string &path){ //string을 받아올때는 포인터
        if(root==nullptr)
            return false;
        if(root->val==Value)
            return true;
        path+='L';
        bool res=getPath(root->left, Value, path);
        if(res) return true;
        path.pop_back();
        path+='R';
        res=getPath(root->right, Value, path);
        if(res) return true;
        path.pop_back();
        return false;
    }
};
