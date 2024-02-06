class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int right=0;

        int zeroes=0;

        int maxOnes=0;

        for(right=0;right<nums.size();right++)
        {
            if(nums[right]==0)
            {
                zeroes++;
            }

            while(zeroes > 1)
            {
                if(nums[left]==0)
                {
                    zeroes--;
                }
                left++;
            }

            maxOnes=max(maxOnes,right-left+1);
            
        }

        return maxOnes-1;
    }
};