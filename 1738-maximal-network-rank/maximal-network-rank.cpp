class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        map<vector<int>, bool> container;
        vector<int> degrees(n,0);
        for(const auto& road: roads){
            container[road] = true;
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){

                if(container[{i,j}] || container[{j,i}]){
                    degrees[i]++;
                }

            }
        }

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