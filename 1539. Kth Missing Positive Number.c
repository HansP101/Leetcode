class Solution{
public:
    int findKthPositive(vector<int>& arr, int k){
    //Binary Search
      //Find index to meet number of missing number is same with k
        int l=0;
        int r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int numOfMissingN=arr[mid]-mid-1;
            if(numOfMissingN<k){
                l=mid+1;
            }
            else
                r=mid-1;
        }
      return r+k+1;   //Nov30/2022 왜그러지?
        
    } 
};

/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int misNumStart=1;
        vector<int> misArray;
        for(auto it: arr){
            while(it>misNumStart){
                misArray.push_back(misNumStart);
                misNumStart++;
            }
            misNumStart=it+1;
        }
        if(k>misArray.size())
            return k-misArray.size()+arr[arr.size()-1];
        else
            return misArray[k-1];
    }
};
*/
