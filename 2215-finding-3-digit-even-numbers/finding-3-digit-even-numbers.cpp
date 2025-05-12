class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> freqMap;
        vector<int> result;
        for(auto d: digits){
            freqMap[d]++;
        }

        for(int i=100;i<1000;i+=2){
            int unit = i / 100;
            int ten  = (i / 10) % 10;
            int hund = i % 10;

            freqMap[unit]--;
            freqMap[ten]--;
            freqMap[hund]--;
            if(freqMap[unit] >= 0 && freqMap[ten] >= 0 && freqMap[hund] >= 0){
                result.push_back(i);
            }
            freqMap[unit]++;
            freqMap[ten]++;
            freqMap[hund]++;
        }

        return result;
    }
};
