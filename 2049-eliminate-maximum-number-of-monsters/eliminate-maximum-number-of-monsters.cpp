class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        int distSize=dist.size();
        int killed=0;
        
        vector<double> timeTaken;
        for(int i=0;i<distSize;i++)
        {
            timeTaken.push_back((double)dist[i]/speed[i]);
        }

        sort(timeTaken.begin(),timeTaken.end());

        int time=0;
        for(auto val:timeTaken)
        {
            if(val>time)
            {
                killed++;
                time++;
            }
            else
            {
                break;
            }
        }

        return killed;
    }
};