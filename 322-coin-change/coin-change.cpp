class Solution {
public:
    int solRecursion(vector<int>&coins,int amount)
    {
        if(amount==0)
        {
            return 0;
        }
        else if(amount<0)
        {
            return INT_MAX;
        }
        int mini=INT_MAX;

        for(int coin: coins)
        {
            int ans=solRecursion(coins,amount-coin);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
        }
        return mini;
    }
    int solMemoization(vector<int>&coins,int amount,vector<int>&DP)
    {
        if(amount==0)
        {
            return 0;
        }
        else if(amount<0)
        {
            return INT_MAX;
        }

        if(DP[amount]!=-1)
        {
            return DP[amount];
        }

        int mini=INT_MAX;

        for(int coin: coins)
        {
            int ans=solMemoization(coins,amount-coin,DP);
            if(ans!=INT_MAX)
            {
                mini=min(mini,1+ans);
            }
        }
        DP[amount]=mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {

        vector<int> Dp(amount+1,-1);
      //  int ans=solRecursion(coins,amount);

        int ans=solMemoization(coins,amount,Dp);

        return ans==INT_MAX?-1:ans;

    }
};