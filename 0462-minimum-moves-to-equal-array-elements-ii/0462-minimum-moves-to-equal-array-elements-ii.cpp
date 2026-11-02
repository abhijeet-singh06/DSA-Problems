class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum =0;
        int median = nums[n/2];
        for(int i=0; i<n; i++){
            sum = sum + abs(nums[i] - median);
        }
        return sum;
    }
};