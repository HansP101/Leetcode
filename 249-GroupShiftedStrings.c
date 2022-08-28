class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        unordered_map<string, vector<int>> defaultMap; //K:string, V: index
        for(int i=0; i<strings.size(); i++){
            string convertedString=convert(strings[i]);
            auto it=defaultMap.find(convertedString);
            if (it!=defaultMap.end()) it->second.push_back(i);
            else defaultMap[convertedString].push_back(i);
        }
        for(auto it: defaultMap){
            vector<string> temp;
            for(auto it2: it.second)
                temp.push_back(strings[it2]);
            ans.push_back(temp);
        }
        return ans;
    }
    string convert(string s){
        string temp;
        int delta=s[0]-'a';
        for(auto c: s){
            if(c-delta<'a')
                temp.push_back(c-delta+26);
            else temp.push_back(c-delta);
        }
        return temp;
    }
};
