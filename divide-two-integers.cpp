#include <climits>
class Solution {
public:
    int divide(int num, int denom) {
        if(!num) return 0;
        if(num == INT_MIN && denom == -1)
            return INT_MAX;
        long dividend = labs(num), divisor = labs(denom);
        long count = 0;
        int sign = ((num < 0) ^ (denom < 0)) ? -1 : 1;
        while(divisor <= dividend) { 
            long copy = divisor, multiples = 1;
            while((copy<<1) <= dividend) {
                copy <<= 1;
                multiples <<= 1;
            }
            count += multiples;
            dividend -= copy;
        }
       
        return sign == 1 ? count : -count;
    }
};
