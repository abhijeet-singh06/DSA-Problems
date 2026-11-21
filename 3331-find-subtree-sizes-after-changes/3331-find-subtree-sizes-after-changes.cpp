class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> path[26];

        function<void(int, int)> dfs = [&](int u, int p) {
            int idx = s[u] - 'a';

            path[idx].push_back(u);

            for(int v : adj[u]) {
                dfs(v, u);
            }

            int newParent = p;

            if(path[idx].size() > 1) {
                newParent = path[idx][path[idx].size() - 2];
            }

            if(newParent != -1) {
                ans[newParent] += ans[u];
            }

            path[idx].pop_back();
        };

        dfs(0, -1);

        return ans;
    }
};