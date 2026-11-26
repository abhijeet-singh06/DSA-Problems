class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) {
            return false;
        }
        int k = 10;
        while (n >= k) {
            if (n - k >= 0) {
                n = n - k;
                k--;
            }
            
        }
        if (k % 2 != 0) {
            return true;
        } else {
            return false;
        }
    }
};