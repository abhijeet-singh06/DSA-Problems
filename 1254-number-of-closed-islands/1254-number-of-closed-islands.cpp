#include <vector>

class Solution {
public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        // 1. Remove/sink any land connected to the outer boundary
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (grid[i][j] == 0) {
                        dfs(grid, m, n, i, j);
                    }
                }
            }
        }
        
        // 2. Count the remaining closed islands
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    dfs(grid, m, n, i, j);
                    ++ans;
                }
            }
        }
        
        return ans;
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int m, int n, int i, int j) {
        // Boundary conditions and check if it's already water (1)
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return;
        }
        
        // Mark current land as water to prevent infinite recursion
        grid[i][j] = 1;
        
        // Explore 4 directions
        dfs(grid, m, n, i + 1, j);
        dfs(grid, m, n, i - 1, j);
        dfs(grid, m, n, i, j + 1);
        dfs(grid, m, n, i, j - 1);
    }
};
