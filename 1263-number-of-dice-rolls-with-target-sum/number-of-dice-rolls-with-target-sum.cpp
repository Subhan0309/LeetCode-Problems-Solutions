class Solution {


public:
    int mod = (pow(10, 9) + 7);
    long long waysToDo(int n, int k, int target, vector<vector<int>>& memo) {
        if(target<0)
        {
            return 0;
        }
        if(n==0 && target!=0)
        {
            return 0;
        }
        if(n!=0 && target==0)
        {
            return 0;
        }
        if (n == 0 && target == 0) {
            return 1;
        }
        if (memo[n][target] != -1) {
            return memo[n][target];
        }

        int ans = 0;
        for (int i = 1; i <= k; i++) {
            int temp = waysToDo(n - 1, k, target - i, memo);
            ans = (ans % mod + temp % mod) % mod;
        }
        memo[n][target] = ans;
        return memo[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> memo(n + 1, vector<int>(target + 1, -1));
        long long ways = waysToDo(n, k, target, memo);
        return static_cast<int>(ways);
    }
};
