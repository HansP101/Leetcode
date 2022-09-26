/* minHeap nlogK : Min Heap은 작은것이 top에 있어서 사이즈 제한을 하기 시작하면, 작은것이 날라가서 큰것들만 남아 있게 된다. */
class Solution {
public:
    struct Comparator{
        bool operator()(const int &a, const int &b){
            return a>=b;
        }
    };
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Comparator> pq;
        for(int i=0; i<nums.size(); i++){
           pq.push(nums[i]);
             if(pq.size()>k)pq.pop();
        }
        return pq.top();
    }
};

/* nlogN sort */
class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](auto &a, auto&b){return a>b;});
        return nums[k-1];
    }
};

/* Quick sort */

class Solution {
public:
int findKthLargest(vector<int>& nums, int k) {
        // could be solved using quick-select algorithms
        // worst case O(n^2) but expected O(n)
        int left=0, right=nums.size()-1;
    while(true){
        int indexPivot=partition(nums, left, right);
        if(indexPivot==k-1)
            return nums[indexPivot];
        else if (indexPivot<k-1){
            left=indexPivot+1;
        }
        else right=indexPivot-1;
    }
}
    int partition(vector<int>&nums, int left, int right){ 
        //return the index/how many element we so far know bigger than pivot we chose here.
        int pivot=nums[left]; //pivot을 가장 처음에 있는 엘레멘트로 해준다. 궂이 끝으로 옮겨줄 필요 없게 하기 위한것도 있고 또 큰 순서대로 나열 시킬껀데 (decreasing order), 모든 수들이 다 작다는 가정도 해놓아야 한다. 
        int pivotLocation=left;
        left++;
        while(left<=right){
            if(nums[left]<pivot and nums[right]>pivot){
                swap(nums[left], nums[right]);
                left++, right--;
            }
            if(nums[left]>=pivot){
                left++;
            }
            if(nums[right]<=pivot){
                right--;
            }
        }
        swap(nums[pivotLocation], nums[right]); //pivot put it to right place. 
        return right;
        }
};
