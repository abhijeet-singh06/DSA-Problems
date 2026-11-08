class Solution {
public:

    bool primeFun(int num) {
    if(num <= 1) return false;

    for(int i = 2; i*i <= num; i++) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

    int diagonalPrime(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        int ans=0;

        for(int i=0; i<min(m,n); i++){
            if(primeFun(nums[i][i])){
                ans = max(ans,nums[i][i]);
            }

            if(primeFun(nums[i][n - i - 1])){
                ans = max(ans, nums[i][n - i - 1]);
            }
        }

        return ans ;


        

    }
};