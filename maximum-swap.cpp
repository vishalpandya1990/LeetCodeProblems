class Solution {
public:
    vector<int> digits;
    int getDigitCount(int n) {
        int i = 0, d;
        while(n) {
            d = n % 10;
            n = n/10;
            digits.push_back(d);
            i++;
        }
        return i;
    }
    int maximumSwap(int num) {
        digits = vector<int>();
        int digitCount = getDigitCount(num);
        reverse(digits.begin(), digits.end());
        int maxDigitToRight;
        for(int r = 0; r < digitCount; r++) {
            int curDigit = digits[r];
            maxDigitToRight = -1;
            for(int j = r+1; j < digitCount; j++) {
                if(digits[j] > curDigit) {
                    if(maxDigitToRight == -1 || digits[j] >= digits[maxDigitToRight])
                        maxDigitToRight = j;
                }
            }
            if(maxDigitToRight != -1) {
                swap(digits[r], digits[maxDigitToRight]);
                break;
            }
        }
        int newNum = 0;
        for(int i = 0; i < digits.size(); i++) {
            newNum = newNum * 10 + digits[i];
        }
        return newNum;
    }
};
