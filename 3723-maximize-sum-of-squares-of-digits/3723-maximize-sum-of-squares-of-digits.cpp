
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string n(num, '0');

        for (int i = 0; i < num; i++) {

            int digit = min(9, sum);
            n[i] = '0' + digit;       //converted to string 
            sum = sum - digit;

            if (sum == 0) {
                break;
            }
        }

        return n;
    }
};
