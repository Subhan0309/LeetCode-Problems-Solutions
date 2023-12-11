class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n=arr.size();
        vector<int> candidates={arr[n/4],arr[n/2],arr[3*n/4]};

        for(int candidate:candidates)
        {
            int left=lower_bound(arr.begin(),arr.end(),candidate)-arr.begin();
            int right=upper_bound(arr.begin(),arr.end(),candidate)-arr.begin()-1;
            if(right-left+1 > n/4)
            {
                return candidate;
            }
        }
        return -1;
    }
};
//1 2 2 3 4
