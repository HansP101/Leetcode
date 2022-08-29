/*
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>k) return k;
            else k++;
        }
        return k;
    }
};
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left=0;
        int right=arr.size()-1;
        
        while(left<=right){
            int mid=(left+right)/2;
            int missingN=arr[mid]-mid-1;
            if ((missingN)<k){
                left=mid+1;
                }
            else 
                right=mid-1;
        }
        return k+right+1;
    }
};
