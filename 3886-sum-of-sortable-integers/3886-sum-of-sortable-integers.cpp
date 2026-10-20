
class Solution {
public:
    bool check(vector<int>& nums, vector<int>& s, int start, int k) {
        vector<int> pat(s.begin() + start, s.begin() + start + k);
        vector<int> block(nums.begin() + start, nums.begin() + start + k);

        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int val = block[i % k];

            while (j > 0 && val != pat[j])
                j = lps[j - 1];

            if (val == pat[j]) j++;

            if (j == k) return true;
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> s = nums;
        sort(s.begin(), s.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;

            for (int i = 0; i < n; i += k) {
                if (!check(nums, s, i, k)) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans += k;
        }

        return ans;
    }
};
