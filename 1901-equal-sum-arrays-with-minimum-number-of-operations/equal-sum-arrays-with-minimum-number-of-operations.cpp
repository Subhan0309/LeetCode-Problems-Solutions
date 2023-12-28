class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {

    int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
    int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
    if(sum1==sum2)
    {
        return 0;
    }

    if (sum2 > sum1)
    {
        vector<int> temp = nums2;
        nums2 = nums1;
        nums1 = temp;
    }

     sum1 = accumulate(nums1.begin(), nums1.end(), 0);
     sum2 = accumulate(nums2.begin(), nums2.end(), 0);



    sort(nums1.begin(), nums1.end(), [](const int a, const int b) -> bool {
        return a > b;
        });

    sort(nums2.begin(), nums2.end());

    int count = 0;

    int a = 0;
    int b = 0;

   

    while (a < nums1.size() && b < nums2.size()) {
        int diff1 = nums1[a] - 1;
        int diff2 = 6 - nums2[b];

        if (diff1>=diff2) {

            int sumDiff = abs(sum1 - sum2);
            
            if (diff1 < sumDiff) {
                nums1[a] = nums1[a] - diff1;
                sum1 = sum1 - diff1;
                count++;
                a++;
            }
            else
            {
                count++;
                a++;
                return count;
            }
        }
        else if(diff2>diff1) {
            int sumDiff = abs(sum1 - sum2);        


            if (diff2 < sumDiff) {
                nums1[b] = nums1[b] + diff2;
                sum2 = sum2 + diff2;
                count++;
                b++;
            }
            else
            {
                count++;
                b++;
                return count;
            }
        }

        if (sum1 == sum2) {
            return count;
        }
    }

    while (a < nums1.size())
    {
        int diff = nums1[a] - 1;
        int sumDiff = abs(sum1 - sum2);

        if (diff < sumDiff) {
            nums1[a] = nums1[a] - diff;
            sum1 = sum1 - diff;
            count++;
            a++;
        }
        else
        {
            count++;
            a++;
            return count;
        }
    }

    while (b < nums2.size())
    {
        int diff = 6 - nums2[b];
        int sumDiff = abs(sum1 - sum2);


        if (diff < sumDiff) {
            nums1[b] = nums1[b] + diff;
            sum2 = sum2 + diff;
            count++;
            b++;
        }
        else
        {
            count++;
            b++;
            return count;
        }
    
    }

    if (sum1 == sum2)
    {
        return count;
    }

    return -1;
}
};