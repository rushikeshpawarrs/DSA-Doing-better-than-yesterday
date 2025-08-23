// Time:  O((n^2 + m^2 + 4 * n * m) * n * m) = O(max(n, m)^3 * min(n, m))
// Space: O(1)
// brute force
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        const auto& minimumArea = [&](int min_i, int max_i, int min_j, int max_j) {
            int min_r = max_i + 1;
            int max_r = min_i - 1;
            int min_c = max_j + 1;
            int max_c = min_j - 1;
            for (int i = min_i; i <= max_i; ++i) {
                for (int j = min_j; j <= max_j; ++j) {
                    if (grid[i][j] == 0) {
                        continue;
                    }
                    min_r = min(min_r, i);
                    max_r = max(max_r, i);
                    min_c = min(min_c, j);
                    max_c = max(max_c, j);
                }
            }
            return min_r <= max_i ? (max_r - min_r + 1) * (max_c - min_c + 1) : 0;
        };

        int result = numeric_limits<int>::max();
        for (int i = 0; i + 1 < size(grid); ++i) {
            int a = minimumArea(i + 1, size(grid) - 1, 0, size(grid[0]) - 1);
            for (int j = 0; j + 1 < size(grid[0]); ++j) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int i = 0; i + 1 < size(grid); ++i) {
            int a = minimumArea(0, i, 0, size(grid[0]) - 1);
            for (int j = 0; j + 1 < size(grid[0]); ++j) {
                const int b = minimumArea(i + 1, size(grid) - 1, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int j = 0; j + 1 < size(grid[0]); ++j) {
            int a = minimumArea(0, size(grid) - 1, j + 1, size(grid[0]) - 1);
            for (int i = 0; i + 1 < size(grid); ++i) {
                const int b = minimumArea(0, i, 0, j);
                const int c = minimumArea(i + 1, size(grid) - 1, 0, j);
                result = min(result, a + b + c);
            }
        }
        for (int j = 0; j + 1 < size(grid[0]); ++j) {
            int a = minimumArea(0, size(grid) - 1, 0, j);
            for (int i = 0; i + 1 < size(grid); ++i) {
                const int b = minimumArea(0, i, j + 1, size(grid[0]) - 1);
                const int c = minimumArea(i + 1, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int i = 0; i + 2 < size(grid); ++i) {
            int a = minimumArea(0, i, 0, size(grid[0]) - 1);
            for (int j = i + 1; j + 1 < size(grid); ++j) {
                const int b = minimumArea(i + 1, j, 0, size(grid[0]) - 1);
                const int c = minimumArea(j + 1, size(grid) - 1, 0, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        for (int i = 0; i + 2 < size(grid[0]); ++i) {
            int a = minimumArea(0, size(grid) - 1, 0, i);
            for (int j = i + 1; j + 1 < size(grid[0]); ++j) {
                const int b = minimumArea(0, size(grid) - 1, i + 1, j);
                const int c = minimumArea(0, size(grid) - 1, j + 1, size(grid[0]) - 1);
                result = min(result, a + b + c);
            }
        }
        return result;
    }
};
