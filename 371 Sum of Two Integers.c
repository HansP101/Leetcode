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

int sumInt(int a, int b){
    u_int32_t carry=0;
    carry=a&b;
    a=a^b;
    carry<<=1;
    while(carry){
        int temp=a^carry;
        carry=a&carry;
        carry<<=1;
        a=temp;
    }
    
    return a;
}

int main(){ 
    int a=3, b=4;
    printf("%d", sumInt(a, b));
    return 0;
}
