class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //Binary search to find the capcity. 
        int l=0, r=0;
        for(auto w: weights){
            if(w>l)l=w;
            r+=w;
        }
        while(l<=r){
            int mid=(l+r)/2;
            int need=totalDays(weights, mid);
            //if(need==days) return mid;
            if(need>days) l=mid+1;
            else r=mid-1;
        }
        return l;
    }
    
    int totalDays(vector<int>&weights, int capacity){
        int loads=0, days=0;
        for(auto w: weights){
            if((loads+w)>capacity)days+=1, loads=w;
            else loads=loads+w;}
        if (loads>0) days++;
        return days;
    }
};
