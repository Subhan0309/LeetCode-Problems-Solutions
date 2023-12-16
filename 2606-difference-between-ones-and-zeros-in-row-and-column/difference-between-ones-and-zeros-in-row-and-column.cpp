class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<int> rows_of_one(n, 0);
    vector<int> cols_of_one(m, 0);
    vector<int> rows_of_zero(n, 0);
    vector<int> cols_of_zero(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                rows_of_one[i]++;
                cols_of_one[j]++;
            } else {
                rows_of_zero[i]++;
                cols_of_zero[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
           
            grid[i][j] = rows_of_one[i] + cols_of_one[j] - rows_of_zero[i] - cols_of_zero[j];
        }
    }

    return grid;
}


};