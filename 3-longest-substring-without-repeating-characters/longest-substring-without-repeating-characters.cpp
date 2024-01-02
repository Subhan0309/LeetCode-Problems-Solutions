class Solution {
public:
   
int lengthOfLongestSubstring(std::string s) {
    std::unordered_map<char, int> myMap;

    int longest = 0;
    int start = 0;  // This variable keeps track of the starting index of the current substring

    for (int i = 0; i < s.size(); i++) {

         // If the character is repeated and the previous occurrence is within the current substring
        if (myMap.find(s[i]) != myMap.end() && myMap[s[i]] >= start) {   

             

            start = myMap[s[i]] + 1;  // Update the starting index of the substring
        }

        // Update the current character's index in the map
        myMap[s[i]] = i;
        // Update the longest substring length
            longest = max(longest, i - start+1);
       
        }

        return longest;
    }
};