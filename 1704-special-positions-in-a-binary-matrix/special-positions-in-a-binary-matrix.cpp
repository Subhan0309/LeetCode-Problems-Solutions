class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<pair<int,int>> positions;

        for(int i =0 ; i < mat.size();i++)
        {
            for(int j=0 ; j < mat[i].size();j++)
            {
                if(mat[i][j]==1)
                {
                    positions.push_back({i,j});
                }
            }
        }
        for(auto pair:positions)
        {
            cout<<pair.first;
            cout<<pair.second;
            cout<<" ";
        }

        int count=0;
        bool found=false;

        for(int i=0;i<positions.size();i++)
        {
            found=false;

            for(int j=0 ; j<positions.size();j++)
            {
                if(i!=j){
                    if(positions[i].first==positions[j].first ||
                    positions[i].second==positions[j].second)
                    {
                        found=true;
                    }
                }
            }

            if(!found)
            {
                count++;
            }
        }
        return count;
    }
};

