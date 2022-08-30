class Solution {
public:
    unordered_map<char, int> AlienDic;

    bool isAlienSorted(vector<string>& words, string order) {
       for(int i=0; i<order.size(); i++) AlienDic[order[i]]=i+1;
       for(int i=0; i<=words.size()-2; i++)
            if(checkAlienOrder(words[i], words[i+1])==false) return false;
        return true;
    }
    bool checkAlienOrder(string w1, string w2){
        int i=0;
        while (i<w1.size() and i<w2.size()){
            if(AlienDic[w1[i]]!=AlienDic[w2[i]])
                return AlienDic[w1[i]]<AlienDic[w2[i]];
            i++;
        }
        return w2.size()>=w1.size();
    }
};
