class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int numofOnes=0, flip=0;
        for (int i=0; i<s.size(); i++){
            if(s[i]=='1')
                numofOnes++;
            else
                flip++;
            flip=min(numofOnes, flip);
        }
        return flip;
    }
};
