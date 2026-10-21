class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end());

        if (s == sorted_s) return 0;
        if (n == 2) return -1;

        char min_ch = sorted_s[0];
        char max_ch = sorted_s[n - 1];

        if (s[0] == min_ch || s[n - 1] == max_ch) return 1;

        bool min_not_at_end = false;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == min_ch) {
                min_not_at_end = true;
                break;
            }
        }

        bool max_not_at_start = false;
        for (int i = 1; i < n; ++i) {
            if (s[i] == max_ch) {
                max_not_at_start = true;
                break;
            }
        }

        if (min_not_at_end || max_not_at_start) return 2;

        return 3;
    }
};