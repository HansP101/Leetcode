class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            int missingN=nums[mid]-nums[0]-mid;
            if(missingN <k){
                start=mid+1;
            }
            else
                end=mid-1;
            }
        return nums[end]+k-(nums[end]-nums[0]-end);    
        }   
};
