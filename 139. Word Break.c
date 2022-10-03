BRUTEFORCE_MEMOIZATION

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<int> memo(s.length(), -1);
        return wordBreakMemo(s, word_set, 0, memo);
    }
    
    bool wordBreakMemo(string s, unordered_set<string>& word_set, int start, vector<int>& memo){
        if(start==s.length())
            return true;
        if(memo[start]!=-1){
            return memo[start];
        }
        for(int end=start+1; end<=s.length(); end++){
            if(word_set.find(s.substr(start, end-start))!=word_set.end() and wordBreakMemo(s, word_set, end, memo)){
                return memo[start]=true;
            }
        }
               return memo[start]=false;
            
    }
};

BFS–QUEUE

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        queue<int> q;
        vector<bool> visited(s.length(), false);
        q.push(0);
        while(q.size()){
            int start=q.front();
            q.pop();
            if(visited[start])
                continue;
            for(int end=start+1; end<=s.length(); end++){
                if(word_set.find(s.substr(start, end-start))!=word_set.end()){
                    q.push(end);
                    if(end==s.length())
                        return true;
                }
            }
            visited[start]=true;
        }
        return false;
    }
};

DP

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length()+1, false);
        dp[0]=true;
        
        for(int i=1; i<=s.length(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] and word_set.find(s.substr(j, i-j))!=word_set.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};
