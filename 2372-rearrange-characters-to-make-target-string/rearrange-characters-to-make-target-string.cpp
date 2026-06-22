class Solution {
public:
    int toInt(char ch){
        return ch - '0' - 49;
    }


    int rearrangeCharacters(string s, string target) {
        vector<int> targetHash(26, 0);
        string targetText = target;
        for(auto ch: targetText){
            targetHash[toInt(ch)]++;
        }

        vector<int> destinationCount(26, 0);
        for(auto ch: s){
            destinationCount[toInt(ch)]++;
        }

        int min = INT_MAX;
        for(auto ch: targetText){
            int holder = destinationCount[toInt(ch)] / targetHash[toInt(ch)];
            if (holder < min){
                min = holder;
            }
        }

        return min; 
    }
};