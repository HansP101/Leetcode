class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        int max=heights[heights.size()-1];
        ans.push_back(heights.size()-1);
        for(int j=heights.size()-2; j>-1; j--){
            if(heights[j]>max){
                max=heights[j];
                ans.push_back(j);
            }
        }
        reverse(ans.begin(), ans.end()); //O(N) better than NlogN for sort.
        return ans;
    }
};1091. Shortest Path in Binary Matrix
