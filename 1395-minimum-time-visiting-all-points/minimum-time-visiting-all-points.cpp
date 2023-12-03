class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total_time = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            vector<int> curr = points[i];
            vector<int> dest = points[i + 1];

            // Move diagonally
            while (curr[0] != dest[0] && curr[1] != dest[1]) {
                if (dest[0] > curr[0]) {
                    curr[0]++;
                } else if (dest[0] < curr[0]) {
                    curr[0]--;
                }

                if (dest[1] > curr[1]) {
                    curr[1]++;
                } else if (dest[1] < curr[1]) {
                    curr[1]--;
                }

                total_time++;
            }

            // Adjust horizontally or vertically
            while (curr[0] != dest[0]) {
                if (dest[0] > curr[0]) {
                    curr[0]++;
                } else {
                    curr[0]--;
                }
                total_time++;
            }

            while (curr[1] != dest[1]) {
                if (dest[1] > curr[1]) {
                    curr[1]++;
                } else {
                    curr[1]--;
                }
                total_time++;
            }
        }

        return total_time;
    }
};
