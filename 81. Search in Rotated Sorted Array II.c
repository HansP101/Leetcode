class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid;
        while(left<=right){
           mid = (left + right) >> 1;//mid = (left + right)/2;
            if(nums[mid]==target) return true;
            if((nums[left]==nums[mid]) and (nums[right]==nums[mid])){++left; --right;}
            else if(nums[mid]>=nums[left]){
                if(nums[mid]>target and target>=nums[left]) right=mid-1;
                else left=mid+1;}
            else{
                if(target>nums[mid] and target<=nums[right]) left=mid+1;
                else right=mid-1;}
            }
    return false;
    }
};
