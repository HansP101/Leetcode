class Solution {
public:
    unordered_map <int, int> HashTable;
    int climbStairs(int n) {
        if (n==0)
            return 1;
        if (n<0)
            return 0;
        auto it = HashTable.find(n);
        if (it != HashTable.end())
            return it->second;
             HashTable[n]= climbStairs(n-2)+climbStairs(n-1);
            return HashTable[n];

    }
};
class Solution {
public:
        int dp[10000]={0};
       int climbStairs(int n) {
        if (n==0)
            return 1;
        if (n<0)
            return 0;
        if(dp[n]!=0) return dp[n];
           dp[n]=climbStairs(n-2)+climbStairs(n-1);
        return dp[n];

    }
};
