class Solution {
public:

    int toInt(char ch){
        return ch - '0' - 49;
    }

    int maxNumberOfBalloons(string text) {

        vector<int> target(26, 0);
        string targetText = "balloon";
        for(auto ch: targetText){
            target[toInt(ch)]++;
        }

        vector<int> destinationCount(26, 0);
        for(auto ch: text){
            destinationCount[toInt(ch)]++;
        }

        int min = INT_MAX;
        for(auto ch: targetText){
            int holder = destinationCount[toInt(ch)] / target[toInt(ch)];
            if (holder < min){
                min = holder;
            }
        }

        return min;
        
    }
};