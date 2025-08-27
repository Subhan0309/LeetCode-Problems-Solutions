class Solution {
public:
    vector<vector<int>> directions = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
    int rows, cols;
    int memoized[501][501][4][2];

    int solve(int i, int j, int d, int canTurn, int targetVal, vector<vector<int>>& grid) {
        int i_ = i + directions[d][0];
        int j_ = j + directions[d][1];

        if (i_ < 0 || i_ >= rows || j_ < 0 || j_ >= cols || grid[i_][j_] != targetVal) {
            return 0;
        }

        if (memoized[i_][j_][d][canTurn] != -1){
            return memoized[i_][j_][d][canTurn];
        }
        int result = 0;
        int keepMoving = 1 + solve(i_, j_, d, canTurn, targetVal == 2 ? 0 : 2, grid);
        result = max(result, keepMoving);

        if (canTurn) {
            int turnAndMove = max(keepMoving, 1 + solve(i_, j_, (d + 1) % 4, 0, targetVal == 2 ? 0 : 2, grid));
            result = max(result, turnAndMove);
        }

        return memoized[i_][j_][d][canTurn] = result;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        memset(memoized, -1, sizeof(memoized));
        int result = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    for( int d = 0 ; d < 4 ; d++ ){
                        result = max(result, 1 + solve(i, j, d, 1, 2, grid));
                    }
                }
            }
        }

        return result;
    }
};
