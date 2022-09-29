/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int* p=&nums[0];
        int N=nums.size();
        k%=N;
        int* newP= new int[N];
        memcpy(newP, p+N-k, sizeof(int)*(k));
        memcpy(newP+k, p, sizeof(int)*(N-k));
        nums.clear();
        nums.insert(nums.begin(), newP, newP+N);
        delete[]newP;
    }
};
*/
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N=nums.size();
        k%=N;
        int leftPtr=0;
        int rightPtr=k;
        vector<int> newNums(N);
        for(int i=0; i<N; i++){
            if(i<N-k){
                newNums[rightPtr]=nums[i];
                rightPtr++;
                }
            else{
                newNums[leftPtr]=nums[i];
                leftPtr++;
            }
        }
        nums=newNums;
    }
};
*/

class Solution {
public:
void rotate(vector<int>& nums, int k) 
    {
        int n=nums.size();
        k=k%n;
        
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        return;
    }
    void reverse(vector<int>&nums, int start, int end)
    {
        while(start<end)
        {
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
};
