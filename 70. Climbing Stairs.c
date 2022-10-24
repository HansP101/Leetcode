
// Climbing Stairs
//Fibonacci

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev = 2, prev2 = 1, res;
        for (int i = 3; i <= n; i++) {
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};



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

//10/24/2022

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+2, 0);
        dp[0]=1;
        for(int i=0; i<n; i++){
            dp[i+1]+=dp[i];
            dp[i+2]+=dp[i];
        }
        return dp[n];
    }
};
