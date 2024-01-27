class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        unordered_map<string,int> myMap;
        int answer=0;

        for(int i=0;i<grid.size();i++)
        {
            vector<int> vec=grid[i];
            string key="";

            for(int j=0;j<vec.size();j++)
            {
                key+=to_string(vec[j]);
                if(j<vec.size()-1)
                {
                    key+=",";
                }
            }
            myMap[key]++;           
        }

        for(int i=0;i<grid[0].size();i++)
        {
            vector<int> col;

            for(int j=0;j<grid.size();j++)
            {
                col.push_back(grid[j][i]);
            }

            string key="";
            for(int j=0;j<col.size();j++)
            {
                key+=to_string(col[j]);
                if(j<col.size()-1)
                {
                    key+=",";
                }
            }
            answer+=myMap[key];
        }

        return answer;
    }
};