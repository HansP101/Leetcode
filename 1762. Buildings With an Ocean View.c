class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> output;
        int maxBlklevel=heights[heights.size()-1];
        output.push_back(heights.size()-1);
        for(int i=heights.size()-1; i>=0; i--){ //Key point는 거꾸로 루프를 돌려서 max 값보다 크다면 ocean view.
            if(heights[i]>maxBlklevel){
                output.push_back(i);
                maxBlklevel=heights[i];
            }   
        }
        reverse(output.begin(), output.end());
        return output;
    }
};
