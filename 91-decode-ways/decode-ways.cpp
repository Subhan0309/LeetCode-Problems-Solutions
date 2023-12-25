class Solution {
public:
    
bool isValid(string str) {
    // Check if the string is valid (non-zero and less than or equal to 26)
    if (str.length() == 1) {
        return str[0] != '0';
    }
    else {
        return str[0] != '0' && stoi(str) <= 26;
    }
}

bool rec(string s, int& count, int si,vector<int>& memo) {
    // Base case: if si reaches the end of the string
    if (si == s.length()) {
        count++;
        return true;
    }
    
    if (memo[si] != INT_MIN)
    {
        count+= memo[si];
        return true;
    }

    // Take one digit
    if (isValid(s.substr(si, 1))) {
        rec(s, count, si + 1,memo);
    }

    // Take two digits if available
    if (si + 1 < s.length() && isValid(s.substr(si, 2))) {
        rec(s, count, si + 2,memo);
    }

    memo[si] = count;
    return true;
}

int numDecodings(string s) {
    vector<int> memo(s.length(),INT_MIN);
    int count = 0;
    rec(s, count, 0,memo);
    return count;
}
};