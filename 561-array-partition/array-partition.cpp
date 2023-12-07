class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i+=2)
        {
            ans+=nums[i];
        }
        return ans;
    }
};
// 1 2 2 5 6 6
// 1 2 3 4 