class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<vector<bool>> connected(n, vector<bool>(n, false));
        vector<int> degrees(n,0);

        for(const auto& road: roads){
            int node1 = road[0];
            int node2 = road[1];

            degrees[node1]++;
            degrees[node2]++;

            connected[node1][node2]=true;
            connected[node2][node1]=true;


        }

        // while calculating maximum , we see degrees & presence of edge 
        // two cities have maximum network rank if the sum of degrees of them is greator of  
        // all pairs.
        // Here is the catch , which is that 
        // We need to minus the degree count from one node if both have edge between them
        // while calculating the sum.


        int maximum = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int sumHolder = degrees[i] + degrees[j];
                if(connected[i][j]){
                    sumHolder -= 1;
                }

                if(sumHolder > maximum){
                    maximum = sumHolder;
                }
            }
        }

        return maximum;

    }
};