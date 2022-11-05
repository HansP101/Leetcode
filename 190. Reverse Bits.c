class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++, n >>= 1) {
            ans<<=1;
            ans |= (n & 1);
        }
        return ans;
    }
};

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        int i=32;
        while(i--){
            ans<<=1;
            ans|=n&0x1;
            n>>=1;     
        }
        return ans;
    }
};
/*
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};


*/
