class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> myMap;

        for(int i=0;i<nums.size();i++)
        {
            myMap[nums[i]]++;
        }

        int count=0;

        for(auto val:myMap)
        {
           if(val.second == 1)
           {
               return -1;
           }

           count += ceil( double(val.second) / 3);
        }

        return count;


    }
};