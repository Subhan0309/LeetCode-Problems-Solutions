class Solution {
public:
    bool isUgly(int n) {
        
        vector<int> primes={2,3,5};
        int curPrime=0;

        while(n && curPrime<primes.size()) 
        {
            if(n % primes[curPrime] == 0)
            {
                n=n/primes[curPrime];
            }
            else
            {
                curPrime+=1;            
            }
        }

        if(n!=1)
        {
            return false;
        }

        return true;
    }
};