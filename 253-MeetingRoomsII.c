class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> timeMap; //key:start or End V;+1 (start) -1 (end)
        int ans=0;
         for(auto it: intervals){
            timeMap[it[0]]+=1;
            timeMap[it[1]]-=1;
        }
        int temp=0;
        for(auto it: timeMap){
            temp+=it.second;
            ans=max(ans, temp);
        }
        return ans;
    }
};
