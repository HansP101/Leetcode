class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> numsTable;
        int minNums=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0)continue;
            numsTable[nums[i]]=i;
        }
        for(int i=1; i; i++){
            if(numsTable.find(i)==numsTable.end())
                return i;
        }
        return -1;
    }
};


/* Binrary Search
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 1;
        sort(nums.begin(),nums.end());
        while(binary_search(nums.begin(),nums.end(),l))
            l++;
        return l;
    }
};
*/



// int findSmallestMissing(int nums[], int low, int high)
// {
//     // base condition
//     if (low > high) {
//         return low;
//     }
 
//     int mid = low + (high - low) / 2;
 
//     // if the mid-index matches with its value, then the mismatch
//     // lies on the right half
//     if (nums[mid] == mid) {
//         return findSmallestMissing(nums, mid + 1, high);
//     }
//     else {
//         // mismatch lies on the left half
//         return findSmallestMissing(nums, low, mid - 1);
//     }
// }
 
// int main(void)
// {
//     int nums[] = { 0, 1, 2, 3, 4, 5, 6 };
//     int n = sizeof(nums) / sizeof(nums[0]);
 
//     int low = 0, high = n - 1;
 
//     printf("The smallest missing element is %d", findSmallestMissing(nums, low, high));
 
//     return 0;
// }
