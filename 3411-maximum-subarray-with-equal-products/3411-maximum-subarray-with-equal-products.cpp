
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                ans = max(ans, 1);
            }

            bool valid = true;

            for(int j = i + 1; j < n; j++) {

                ans = max(ans, 2);

                for(int k = i; k < j; k++) {
                    if(gcd(nums[k], nums[j]) != 1) {
                        valid = false;
                        break;
                    }
                }

                if(!valid) break;

                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
