class Solution {
public:
    //sum only with bit operation wihtou + operation
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
