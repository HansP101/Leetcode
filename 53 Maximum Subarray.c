
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //Kadane's algorithm.
        int subSum=0;
        int maxSum=INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            subSum+=nums[i];
            if(subSum>maxSum) maxSum=subSum;
            if(subSum<0)subSum=0;
        }
        return maxSum;
    }
};

/* burte force
class Solution{
    public:
    int maxSubArray(vector<int>&nums){
        int maxSum=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            int subSum=0;
            for(int j=i; j<nums.size(); j++){
                subSum+=nums[j];
                if(subSum>maxSum) maxSum=subSum;
            }
        }
        return maxSum;
    }
};

*/
