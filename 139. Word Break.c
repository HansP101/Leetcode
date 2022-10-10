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
        vector<bool> visited(s.length(), false); // 이게 없으면 이미 실패했던것을 또 시도하게 된다 낭비이고, 결국엔 TLE 까지 간다. 
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
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        for(int i=1; i<=s.size(); i++){//i: end point
            if (dp[i]==true) continue;
            for(int j=0; j<i; j++){ //j: starting point
                if(dp[j]==true and wordSet.find(s.substr(j, i-j))!=wordSet.end()) dp[i]=true;
            }
        }
        return dp[s.size()];
        
    }
};
