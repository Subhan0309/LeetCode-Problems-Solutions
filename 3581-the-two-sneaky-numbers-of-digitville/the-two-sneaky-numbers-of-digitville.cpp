class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;

        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]+1;
        }

        for(auto a:nums)
        {
            if(nums[abs(a)-1] < 0)
            {
                ans.push_back(abs(a)-1);
            }
            nums[abs(a)-1] = - (abs(nums[abs(a)-1]));
        }

        return ans;
    }
};