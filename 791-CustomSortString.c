class Solution {
public:
    struct charOrder{
        char c;
        int prio;
    };
    
    string customSortString(string order, string s) {
        string ans;
        vector<charOrder> orderStr;
        unordered_map<int, char> orderMap;
        int ssize=s.size();
        for(int i=0; i<order.size();i++){
            orderMap[order[i]]=i;
        }
        for(auto it: s){
            if(orderMap.find(it)!=orderMap.end()){
                orderStr.push_back({it, orderMap[it]});
            }else
                orderStr.push_back({it, --ssize});
        }
        sort(orderStr.begin(), orderStr.end(), [](auto &a, auto&b){return a.prio<b.prio;});
        for(auto it: orderStr){
            ans.push_back(it.c);
        }
        return ans;
    }
};
