class Solution {
public:
    int kthFactor(int n, int k) {
        unordered_map<int, int> hashTable;
        vector<int> factors;
        if(n==1)
            return 1;
        for(int i=1; i<=n/2; i++){
        if (n%i==0){
            if(hashTable.find(i)==hashTable.end()){
                factors.push_back(i);
                hashTable[i]=1;
                }
            if(hashTable.find(n/i)==hashTable.end()){
                factors.push_back(n/i);
                hashTable[n/i]=1;
                }
              }
             }

        sort(factors.begin(), factors.end(), [](int i, int j){return i<j;});
        if (factors.size()<k)
            return -1;
        else
            return factors[k-1];   
    }
};
