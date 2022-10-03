class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lhs(nums.size(), 1);
        vector<int> rhs(nums.size(),1);
        vector<int> ans(nums.size(), 0);
        for(int i=1; i<nums.size(); i++){
            lhs[i]=lhs[i-1]*nums[i-1];
        }
        for(int i=nums.size()-2; i>=0; i--){
            rhs[i]=rhs[i+1]*nums[i+1];
        }
         for(int i=0; i<nums.size(); i++){
            ans[i]=lhs[i]*rhs[i];
        }
        return ans;
    }
};
