class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(auto a:nums)
        {
            if(nums[abs(a)-1] < 0)
            {
                ans.push_back(abs(a));
            }
            nums[abs(a)-1] = -(abs(nums[abs(a)-1]));
        }


    return ans;

    }
};
