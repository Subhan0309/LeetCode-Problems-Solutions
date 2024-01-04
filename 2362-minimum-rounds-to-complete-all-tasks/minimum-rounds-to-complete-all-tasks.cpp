class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> myMap;

        for(auto x:tasks)
        {
            myMap[x]++;
        }

        int ans =0;
        for(auto x:myMap)
        {
            if(x.second==1)
            {
                return -1;
            }
            ans += ceil(double(x.second)/3);
        }
        return ans;
    }
};