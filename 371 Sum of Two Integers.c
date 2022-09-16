class Solution {
public:
    int getSum(int a, int b) {
        uint32_t carry; //
        while(b!=0){
             carry=a&b;
            a=a^b;
            b=carry<<1;
        }
        return a;
        
    }
};
