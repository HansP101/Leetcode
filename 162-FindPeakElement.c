class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()==1) return 0;
        return binarySearch(0, nums.size()-1, nums);
    }
    int binarySearch(int start, int end, vector<int>& nums){
        while(start<end){
            int mid=(start+end)/2;
            if(nums[mid]>nums[mid+1])
                end=mid;
            else start=mid+1;
        }
        return start;
    }
};
