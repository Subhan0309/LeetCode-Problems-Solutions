class Solution {
public:
    int firstUniqChar(string s) {
    unordered_map<char, int> freqMap;

    for (auto ch : s)
    {
        freqMap[ch]++;
    }

    char result;

    

    for (int i = 0; i < s.length(); i++)
    {
        if (freqMap[s[i]] == 1)
        {
            return i;
       }
    }

    return -1;


}
};