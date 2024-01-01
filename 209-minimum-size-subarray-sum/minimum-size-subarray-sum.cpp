class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    for (int x : nums) {
        sum += x;
    }

    if (sum < target) {
        return 0;
    }

    int p1 = 0;
    int p2 = 0;

    sum = nums[p1];
    int minLen = INT_MAX;

    int len = nums.size();

    while (p1 < len && p2 < len) {
        if (sum >= target) {
            int windowSize = p2 - p1 + 1;
            minLen = min(minLen, windowSize);
            sum -= nums[p1];
            p1++;

            if (p1 > p2) {
                // Ensure p2 is not behind p1
                p2 = p1;
                if (p2 < len) {
                    sum += nums[p2];
                }
            }
        } else {
            p2++;
            if (p2 < len) {
                sum += nums[p2];
            }
        }
    }

    return minLen == INT_MAX ? 0 : minLen;
}


};