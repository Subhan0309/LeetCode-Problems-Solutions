class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size=nums.size();

        vector<int> ans;

        for(auto a:nums)
        {
            nums[abs(a)-1] = -abs(nums[abs(a)-1]);
        }
        // [4,3,-2,-7,8,2,3,1]
        for(int i=0;i<size;i++)
        {
            if(nums[i]>0){
                ans.push_back(i+1);  
            }
        }

        return ans;
    }
};