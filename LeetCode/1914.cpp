class Solution {
public:
    void rotate_layer(vector<vector<int>>& grid, int layer, int k) {
        int n = grid.size() - 1 - layer;
        int m = grid[0].size() - 1 - layer;

        k %= 2 * (n + m) - 4 * layer;
        if (k == 0) {
            return;
        }

        vector<int> arr;
        for (int i = layer; i < n; ++i) {
            arr.push_back(grid[i][layer]);
        }
        for (int i = layer; i < m; ++i) {
            arr.push_back(grid[n][i]);
        }
        for (int i = n; i > layer; --i) {
            arr.push_back(grid[i][m]);
        }
        for (int i = m; i > layer; --i) {
            arr.push_back(grid[layer][i]);
        }

        int idx = (arr.size() - k);
        for (int i = layer; i < n; ++i) {
            grid[i][layer] = arr[idx++];
            idx %= arr.size();
        }
        for (int i = layer; i < m; ++i) {
            grid[n][i] = arr[idx++];
            idx %= arr.size();
        }
        for (int i = n; i > layer; --i) {
            grid[i][m] = arr[idx++];
            idx %= arr.size();
        }
        for (int i = m; i > layer; --i) {
            grid[layer][i] = arr[idx++];
            idx %= arr.size();
        }
    }

    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int layer = 0;
        const int number_of_layer = min(n, m) / 2;

        while (layer < number_of_layer) {
            rotate_layer(grid, layer++, k);
        }

        return grid;
    }
};