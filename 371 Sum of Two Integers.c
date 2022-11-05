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

class Solution {
public:
    int getSum(int a, int b) {
        int ans=0;
        uint32_t carryOver=0;
        int bitPos=0;
        carryOver=a&b;
        ans=a^b;
        while(carryOver){
            carryOver=carryOver<<1;
            int temp=carryOver^ans;
            carryOver=carryOver&ans;
            ans=temp;
        }
        return ans;
    }
};
