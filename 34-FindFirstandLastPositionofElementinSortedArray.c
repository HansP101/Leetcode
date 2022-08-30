/*
And in a binary search for 5:

       v-- lower bound: index4, first "5"
1 2 3 4 5 5 5 6 7 9
             ^-- upper bound: index6, last "5"
*/

class Solution{
    public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = upper_bound(nums, target);
        
        if (idx1 <= idx2 and nums[idx1]==target)
            return {idx1, idx2};
        else
            return {-1, -1};
           
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (r-l)/2+l;
            if (nums[mid] < target)
                l= mid+1;
            else
                r = mid-1; //같으면 계속 오른쪽 바운더리를 줄여온다. 
        }
        return l;
    }
        int upper_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = (r-l)/2+l;
            if (nums[mid] > target)
                r= mid-1;
            else
                l = mid+1; //같으면 계속 왼쪽 바운더리를 증가시킨다.
        }
        return r;
    }
};
