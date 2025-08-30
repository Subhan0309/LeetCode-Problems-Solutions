class Solution {
public:
    long long flowerGame(int n, int m) {
        long long onePossibility = 1L * ((n+1)/2) * (m/2);
        long long secondPossibility = 1L * (n/2) * ((m+1)/2);

        // (x - odd, y - even) * (x - even, y - odd)
        

        return onePossibility + secondPossibility;
    }
};
