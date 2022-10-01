class Solution {
public:
    int reverse(int x) {    
        auto sign = x < 0;
        int x_rev = 0;
        while (x) {
            int d = x % 10; // first digit
            x /= 10; // remove first digit
            // Check for positive overflow
            if (!sign && x_rev > (INT_MAX - d) / 10) {
                return 0;
            }
            // Check negative overflow
            if (sign && x_rev < (INT_MIN - d) / 10) {
                return 0;
            }
            x_rev *= 10; // shift digit
            x_rev += d; // insert digit
        }
        return x_rev;
    }
}
