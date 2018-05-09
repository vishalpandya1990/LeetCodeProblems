class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        //if(n > 9) return countNumbersWithUniqueDigits(9);
        if(n == 0) return 1;
        if(n == 1) return 10;
        int rem = countNumbersWithUniqueDigits(n-1);
        int x = 9, res = 1;
        for(int i = 0; i < n; i++) {
            res = res * x;
            if(i) x--;
        }
        return rem + res;
    }
};
