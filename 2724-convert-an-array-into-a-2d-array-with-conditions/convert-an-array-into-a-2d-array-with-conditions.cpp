#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<std::vector<int>> findMatrix(std::vector<int>& nums) {
        std::vector<std::vector<int>> ans;
        std::unordered_map<int, int> freqMap;

        // Count the frequency of each element in nums
        for (auto x : nums) {
            freqMap[x]++;
        }

        // Find the maximum frequency
        int high = -1;
        for (const auto& entry : freqMap) {
            if (entry.second > high) {
                high = entry.second;
            }
        }

        // Initialize ans with empty vectors
        ans.resize(high);

        // Fill ans with elements based on their frequencies
        for ( auto& entry : freqMap) {
            int num = entry.first;
            int freq = entry.second;
            int x=freq;
            for (int i = 0; i < x; i++) {
                ans[freq - 1].push_back(num);
                freq--;
            }
        }

        return ans;
    }
};
