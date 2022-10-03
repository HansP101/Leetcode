class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end(), [](string a1, string a2){return a1<a2;});
        for (int i=0; i<searchWord.size(); i++){
            vector<string> temp;
            string ch=searchWord.substr(0, i+1);
            for(auto it: products){
                if(it.find(ch)==0 and temp.size()<3)
                    temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
