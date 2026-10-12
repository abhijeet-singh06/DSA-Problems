class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        
        vector<int> bitCounts(31, 0);
        for (int num : nums) {
            for (int i = 0; i < 31; ++i) {
                if ((num >> i) & 1) {
                    bitCounts[i]++;
                }
            }
        }
        
        long long totalSumOfSquares = 0;
   
        for (int i = 0; i < k; ++i) {
            long long currentNumber = 0;
            for (int bit = 0; bit < 31; ++bit) {
                if (bitCounts[bit] > 0) {
                    currentNumber |= (1LL << bit); 
                    bitCounts[bit]--;              
                }
            }
            totalSumOfSquares = (totalSumOfSquares + (currentNumber * currentNumber) % MOD) % MOD;
        }
        
        return totalSumOfSquares;
    }
};