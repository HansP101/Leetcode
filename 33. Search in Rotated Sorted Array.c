class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(n==1){
            if(nums[0]==target)
                return 0;
            else return -1;
        }
        int pivot=findRotateIndex(nums, 0, n-1);
        
            // if target is the smallest element
    if (nums[pivot] == target)
      return pivot;
    // if array is not rotated, search in the entire array
    if (pivot == 0)
      return binarySearch(nums, 0, n - 1,target);
        
       if(target<nums[0])
           return binarySearch(nums, pivot, n-1, target);
        else
            return binarySearch(nums, 0, pivot, target);
        
    }
    int findRotateIndex(vector<int>& nums, int left, int right){
        if(nums[left]<nums[right])
            return 0;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[mid+1])
                return mid+1; 
            else{
                if(nums[mid]<nums[left])
                    right=mid-1; //pivot is in left side
                else
                    left=mid+1;
            }
        }
        return 0;
    }
    
    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            else{
                if(target<nums[mid])
                    right=mid-1; 
                else
                    left=mid+1;
            }
        }
        return -1;
        
    }
};
