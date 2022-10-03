class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0, payload;
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>&a,const vector<int>&b){return a[1]>b[1];});
        for(int i=0; i<boxTypes.size(); i++){
            if(!truckSize) break;
            payload=min(truckSize, boxTypes[i][0]);
            truckSize-=payload;
            ans+=payload*boxTypes[i][1];
        }
        return ans;
    }
};
