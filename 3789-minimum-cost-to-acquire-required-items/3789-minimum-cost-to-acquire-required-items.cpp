
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        long long case1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        long long case2 = 1LL * max(need1, need2) * costBoth;

        long long common = min(need1, need2);

        long long case3 = common * costBoth
                        + 1LL * (need1 - common) * cost1
                        + 1LL * (need2 - common) * cost2;

        return min({case1, case2, case3});
    }
};
