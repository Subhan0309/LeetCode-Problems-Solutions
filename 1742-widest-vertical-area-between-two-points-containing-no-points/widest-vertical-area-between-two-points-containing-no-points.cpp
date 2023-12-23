class Solution {
public:
   int maxWidthOfVerticalArea(vector<vector<int>>& points) {

    sort(points.begin(), points.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
   

    int max = INT_MIN;

    for (int i = 0; i < points.size()-1; i ++)
    {
        int diff = (points[i + 1][0] - points[i][0]);
        if (max < diff)
        {
            max = diff;
        }
    }

    return max;

}
};