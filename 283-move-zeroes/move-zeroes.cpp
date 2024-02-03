class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length=nums.size();
        int zeroes=0;
        for(auto num:nums)
        {
            if(num==0)
            {
                zeroes++;
            }
        }
        if(length==zeroes)//means the array already contains all zeroes
        {
            return;
        }

        for(int i=0;i<length;i++)
        {
            if(nums[i]==0)
            {
                for(int j=i+1;j<length;j++) // loop to find the non-zero digit
                {
                    if(nums[j])
                    {
                        int temp=nums[j];
                        nums[j]=nums[i];
                        nums[i]=temp;
                        break;
                    }
                }
            }
        }     

        // if we found a zero , shift the whole array to left , and enter a zero at the end .  

    }
};