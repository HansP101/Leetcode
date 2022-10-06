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


class Solution {
public:
    struct Comparator{  
        bool operator()(int a, int b){return a>b;} //minHeap 
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans=1;
        priority_queue<int, vector<int>, Comparator> pq;
        sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){return a[0]==b[0]? a[1]<b[1]: a[0]<b[0];});
        pq.push(intervals[0][1]);
        for(int i=1; i<intervals.size(); i++){
            if(pq.top()<=intervals[i][0]) pq.pop(); //already meeting room was evacuated
            pq.push(intervals[i][1]);
            int pqSize=pq.size();
            ans=max(ans, pqSize);
        }
        return ans;
    }
};

class Solution {
public:
    struct Comparator{
        bool operator()(int &a, int &b){return a>b;}//minHeap;
    };
   
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans=1;
        priority_queue<int, vector<int>,  Comparator> pq;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){return a[0]==b[0]? a[1]<b[1]: a[0]<b[0];});
        pq.push(intervals[0][1]);
        for(auto it=intervals.begin()+1;it!=intervals.end(); it++){
            if((*it)[0]>=pq.top())pq.pop(); //previous meeting is already over
            pq.push((*it)[1]);
            int temp=pq.size();
            ans=max(ans, temp);
        }
        return ans;
    }
};

class Solution {
public:
    struct Comparator{
        bool operator()(const pair<int, int>&a, const pair<int, int>&b){return a.second>b.second;} //minHeap
    };
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b){return a[0]==b[0]? a[1]<b[1]: a[0]<b[0];});
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
        pq.push({intervals[0][0], intervals[0][1]});
        int ans=1;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=pq.top().second)pq.pop();
            pq.push({intervals[i][0], intervals[i][1]});
            int temp=pq.size();
            ans=max(ans, temp);
        }
                                                                                
        return ans;
    }
};
