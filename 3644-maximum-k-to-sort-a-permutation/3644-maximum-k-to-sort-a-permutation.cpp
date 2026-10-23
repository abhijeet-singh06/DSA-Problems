class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                if (ans == -1)
                    ans = nums[i];
                else
                    ans = ans & nums[i];
            }
        }
        if (ans == -1) {
            ans = 0;
        }
        return ans;
    }
};

;