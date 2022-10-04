class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         int currentWindowSum=0;
         int MaxWindowSum=0;

        for(int i=0; i<k;i++){
            currentWindowSum+=nums[i];
        }
        MaxWindowSum=currentWindowSum;
        for(int i=k; i<nums.size(); i++){
            currentWindowSum=currentWindowSum+nums[i]-nums[i-k];
            MaxWindowSum=max(MaxWindowSum,currentWindowSum);
        }
        return (double)MaxWindowSum/k;
    }
};
