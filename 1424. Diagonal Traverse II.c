class Solution{
public:
vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> answer;
        map<int, vector<int>> m;
        int maxKey = 0; // maximum key inserted into the map i.e. max value of i+j indices.
        
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums[i].size(); j++) {
                m[i+j].push_back(nums[i][j]); // insert nums[i][j] in bucket (i+j).
            }
        }
        for (int i=0; i<m.size(); i++){
            for(auto x= m[i].rbegin();x!=m[i].rend(); x++)
                answer.push_back(*x);
        }
        
        return answer;
    }
};
