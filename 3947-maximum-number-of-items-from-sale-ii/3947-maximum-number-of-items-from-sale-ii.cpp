class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> total(n + 1, 0);

        int minPrice = INT_MAX;

        for (auto &item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                total[i] += freq[j];
            }
        }

        vector<pair<int, int>> bonus;

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            int freeItems = total[factor] - 1;

            if (freeItems > 0) {
                bonus.push_back({price, freeItems});
            }
        }

        sort(bonus.begin(), bonus.end());

        int ans = 0 ;

        for (auto &[price, count] : bonus) {
            if (price >= 2 * minPrice) {
                break;
            }

            int buy = min(count, budget / price);

            ans += 2 * buy;
            budget -= buy * price;
        }

        ans += budget / minPrice;

        return ans;
    }
};