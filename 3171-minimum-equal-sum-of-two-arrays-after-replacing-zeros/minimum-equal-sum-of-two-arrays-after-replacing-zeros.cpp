class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zeroes1 = 0, zeroes2 = 0;
        for(int i = 0 ; i < nums1.size() ; i++ ) {
            sum1 += nums1[i];
            if (nums1[i] == 0) {
                sum1++; 
                zeroes1 += 1;
            }
        }

        for(int i = 0 ; i < nums2.size() ; i++ ) {
            sum2 += nums2[i];
            if (nums2[i] == 0) {
                sum2++;
                zeroes2 += 1;
            }
        }

        if ( !zeroes1 && sum2 > sum1 || !zeroes2 && sum1 > sum2)
        {
            return -1;
        }

        return max(sum1, sum2);
    }
};
