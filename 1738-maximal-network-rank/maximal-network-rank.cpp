class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        map<vector<int>, bool> container;
        vector<int> degrees(n,0);
        // storing edges presence in hash for faster lookup
        for(const auto& road: roads){
            container[road] = true;
        }

        // calculating the degree for every node
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){

                if(container[{i,j}] || container[{j,i}]){
                    degrees[i]++;
                }

            }
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
                if(container[{i,j}] || container[{j,i}]){
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