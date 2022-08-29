class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start=0, end=0; //sliding window
        int ans=0;
        for(end; end<nums.size(); end++){
            if(nums[end]==0)k--;
            while(k<0){
                if(nums[start]==0)k++;
                start++;}            
            int temp=end-start+1;
            ans=max(ans, temp);
        }
        return ans;
    }
};
