class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> mapin;

        for (const string& word : words) {
            for (char c : word) {
                mapin[c]++;
            }
        }

        int n = words.size();

        for (const auto& entry : mapin) {
            if (entry.second % n != 0) {
                return false;
            }
        }

        return true;
    }
};