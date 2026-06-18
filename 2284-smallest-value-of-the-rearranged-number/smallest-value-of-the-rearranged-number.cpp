class Solution {
public:
    long long smallestNumber(long long num) {

        if(num == 0) return 0;

        bool positive = num > 0;

        vector<int> digits;

        long long n = abs(num);

        while(n){
            digits.push_back(n % 10);
            n /= 10;
        }

        if(positive){

            sort(digits.begin(), digits.end());

            int idx = 0;

            while(digits[idx] == 0)
                idx++;

            swap(digits[0], digits[idx]);

            long long ans = 0;

            for(int d : digits)
                ans = ans * 10 + d;

            return ans;
        }
        else{

            sort(digits.begin(), digits.end(), greater<int>());

            long long ans = 0;

            for(int d : digits)
                ans = ans * 10 + d;

            return -ans;
        }
    }
};