class Solution {
public:
    vector<int> weighted;
    Solution(vector<int>& w) {
        weighted.resize(w.size());
        int subsum=0;
        for(int i=0; i<w.size(); i++){
            subsum+=w[i];
            weighted[i]=subsum;
        }
    }
    
    int pickIndex() {
        return upper_bound(weighted.begin(), weighted.end(), rand()%weighted[weighted.size()-1])-weighted.begin();
    }
};
