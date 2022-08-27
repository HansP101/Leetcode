class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (int i=1; i<=intervals.size(); i++){
            if(i<intervals.size()&&intervals[i-1][1]>=intervals[i][0]){
                //overlapped
                intervals[i][1]=max(intervals[i-1][1], intervals[i][1]);
                intervals[i][0]=intervals[i-1][0];
            }
            else
                ans.push_back({intervals[i-1][0],intervals[i-1][1]});
            
        }
        return ans;
    }
};
/*8/25풀이:
class Solution{
public:

vector<vector<int>> merge(vector<vector<int>>& intervals){
    vector<vector<int>> ans;

	sort(intervals.begin(), intervals.end(), [](auto &a, auto&b){return a[0]<b[0];});

    ans.push_back(intervals[0]);
    for(int i=1; i<intervals.size(); i++){
	    if(ans[ans.size()-1][1]>=intervals[i][0]){
		//overwrapped!
		vector<int> temp={ans[ans.size()-1][0], max(ans[ans.size()-1][1], intervals[i][1])};
		ans.pop_back();
		ans.push_back(temp);
        }
        else
            ans.push_back(intervals[i]);
                                              }
    return ans;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){return a[0]<b[0];});
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i-1][1]>=intervals[i][0]){
                //overlapped;
                intervals[i][0]=intervals[i-1][0];
                intervals[i][1]=max(intervals[i-1][1], intervals[i][1]); //키포인트는 오버렙 되었을때 넥스트 엘레먼트의 값을 업데이트 해 가서 계속 그 값을 비교하겠다는것. 
            }else
                ans.push_back(intervals[i-1]);
        }
        ans.push_back(intervals[intervals.size()-1]);
        return ans;
    }
};




class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto interval : intervals){ 
            if(ans.empty() || interval[0]>ans.back()[1]){ //no overlapped
                ans.push_back(interval);
            }
            else
                ans.back()[1]=max(interval[1],ans.back()[1]);
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<vector<int>> stack;
         vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), [](auto &v1, auto&v2){ return v1[0]< v2[0];});
        stack.push(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            auto it=stack.top();
            if(it[1]>=intervals[i][0]){
                stack.pop();
                stack.push({it[0], max(it[1], intervals[i][1])});
            }
            else{
                stack.push(intervals[i]);
            }
        }
        while(stack.size()){
            auto it=stack.top();
            stack.pop();
            ans.push_back(it);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

