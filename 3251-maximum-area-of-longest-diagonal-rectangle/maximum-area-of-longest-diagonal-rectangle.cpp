class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiag = -1;
        int maxArea = -1;

        for (auto& d : dimensions) {
            int area = d[0] * d[1];
            double diag = sqrt(1.0 * d[0] * d[0] + 1.0 * d[1] * d[1]);

            if (diag > maxDiag || (diag == maxDiag && area > maxArea)) {
                maxDiag = diag;
                maxArea = area;
            }
        }

        return maxArea;
    }
};
