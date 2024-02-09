class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> me;

        for(auto ar:arr)
        {
            me[ar]++;
        }



        unordered_map<int,int> maine;

        for(auto ar:me)
        {
            maine[ar.second]++; //maintaining the count of ocurrences , whether two numbers repeated same number of times or not 
        }

        for(auto ar:maine)
        {
            if(ar.second>=2)
            {
                return false;
            }
        }
        return true;
    }
};