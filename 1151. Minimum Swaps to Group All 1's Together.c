class Solution {
public:
    int minSwaps(vector<int>& data) {
        int slidingWindowSize=0;
        int ans=INT_MAX;
        int numOfswutching=0;
        int currWindow=0;
        for (int i=0; i<data.size(); i++){
            if(data[i]==1)
                slidingWindowSize++;
        }
        if (slidingWindowSize==0)
            return 0;
        
        //[1,0,1,0,1,0,0,1,1,0,1]
        for (int i=0; i<data.size(); i++){
                if(data[i]==0)
                    numOfswutching++;
            currWindow++;
                if(currWindow==slidingWindowSize){
                    currWindow--;
                    if(numOfswutching<ans)
                        ans=numOfswutching;
                    if(data[i-slidingWindowSize+1]==0)
                        numOfswutching--;
                }   
        }
        return ans;
    }
};
