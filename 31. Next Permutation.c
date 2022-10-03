/*
546321(ans:561234)
뒤에서 부터 보면서 숫자가 작아지기 시작하는 수가 바뀌어야 하는 수이다. 
Find"4" which has to be change one: upto hear the index,2
And then sort: 541236
Find bigger than "4"->6 and swap:561234
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Step1: find possible candidate to change
        int lastIndex=nums.size()-1;
        while(lastIndex!=0 and nums[lastIndex-1]>= nums[lastIndex]){
            lastIndex--;
        } 
        //Step2: sort the number
        sort(nums.begin()+lastIndex, nums.end(), [](auto &a, auto &b){return a<b;});
        //step3: find the larger than candidate
        if(lastIndex!=0){
            auto it=upper_bound(nums.begin()+lastIndex, nums.end(), nums[lastIndex-1]);
            arrayLocationSwap(nums, lastIndex-1, it-nums.begin());
        }
    }
    void arrayLocationSwap(vector<int>&nums, int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};
