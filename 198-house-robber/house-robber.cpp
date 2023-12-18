class Solution {
public:

    int robHelper(vector<int>& nums,int index,vector<int>&memo) {

        if(index==nums.size()-1)
        {
            return nums[index];
        }
        else if(index>nums.size()-1)
        {
            return 0;
        }

        if(memo[index]!=INT_MIN)
        {
            return memo[index];
        }

        int max=INT_MIN;

       int robbed=nums[index]+robHelper(nums,index+2,memo);
       int notRobbed=0+robHelper(nums,index+1,memo);

        max=robbed>notRobbed?robbed:notRobbed;

        memo[index]=max;
        return max;


    }

    int rob(vector<int>& nums) {

        vector<int>memo(nums.size(),INT_MIN);
        return robHelper(nums,0,memo);

        
    }
};