class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordSet;
        unordered_map<string, int> memo;
        for(auto it: words){
            wordSet.insert(it);
        }
        int ans=0;
        for(auto it: words){
            ans=max(ans, dfs(wordSet, memo, it));
        }
        return ans;
    }
    int dfs(unordered_set<string>& wordSet, unordered_map<string, int> &memo, string currentWord){
        if(memo.find(currentWord)!=memo.end()) return memo[currentWord];
        int maxLength=1;
        for(int i=0; i<currentWord.size(); i++){
            string newWord=currentWord.substr(0, i)+currentWord.substr(i+1);
            if(wordSet.find(newWord)!=wordSet.end()){
                maxLength=max(maxLength, 1+dfs(wordSet, memo, newWord));
            }
        }
        memo[currentWord]=maxLength;
        return maxLength;
    }
};
