class Solution {
public:
    int noOf1s(string &s)
    {
        int count=0;
        for(auto ch:s)
        {
            if(ch=='1')
            {
                count++;
            }
        }
        return count;
    }
    string maximumOddBinaryNumber(string s) {
        int size=s.length();
        int ones=noOf1s(s);
        int zeroes=size-ones;

        if(ones==size || zeroes==size)
        {
            return s;
        }

        string result="";

        while(ones>1)
        {
            result+="1";
            ones--;
            
        }
        while(zeroes)
        {
            result+="0";
            zeroes--;            
        }
        result+="1";
        return result;      


    }
};