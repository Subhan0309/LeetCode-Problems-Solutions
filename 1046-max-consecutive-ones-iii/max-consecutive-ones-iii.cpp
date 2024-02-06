class Solution {
public:
int longestOnes(vector<int>& nums, int k) {

        //Brute Force Solution
        // int max = -1;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     int count = 0;
        //     int holder = k;
        //     for (int j = i; j < nums.size(); j++)
        //     {
        //         if (nums[j] == 0 && holder)
        //         {
        //             --holder;
        //         }
        //         else if (nums[j] == 0 && holder <= 0)
        //         {
        //             break;
        //         }
        //         count++;
        //     }

        //     if (count > max)
        //     {
        //         max = count;
        //     }

        // }

        // return max;


        // }

    // For each A[j], try to find the longest subarray.
    // If A[i] ~ A[j] has zeros <= K, we continue to increment j.
    // If A[i] ~ A[j] has zeros > K, we increment i (as well as j).

    int left=0;
    int right=0;
    int maximum=0;

    int CountZeroes=0;

    for(right=0;right<nums.size();right++)
    {
        if(nums[right]==0)
        {
            CountZeroes++;
        }

        while(CountZeroes>k)
        {
            if(nums[left]==0)
            {
                CountZeroes--;
            }

            left++;
        }


        maximum=max(maximum,right-left+1);
    }

    return maximum;
}

};