class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int index = 0;
        for(auto  cost :costs){
            index++;
            coins -= cost;

            if(coins == 0){
                return index;
            }else if(coins < 0){
                return index-1;
            }
        }

        return index;
    }
};