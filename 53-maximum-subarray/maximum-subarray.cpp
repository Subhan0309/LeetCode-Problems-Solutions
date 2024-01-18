class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        if(nums.size() == 1){
            return nums[0];
        }
        bool flag = false;
        int minim = INT_MIN;
        for (auto x: nums){
            
            if(x >= 0){
                flag = true;
                break;
            }
            else
            {
                if(x > minim){
                    minim = x;
                }
            }
        }
        if (!flag){
            return minim;
        }
        int max_ending_here=0;
        int max_soo_far=0;

        for(int i=0;i<nums.size();i++)
        {
            max_ending_here=max(nums[i],max_ending_here+nums[i]);
            max_soo_far=max( max_soo_far,max_ending_here);
        }

        return max_soo_far;
    }
};