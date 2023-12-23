class Solution {
public:
    // int countOccurence(char x,string s)
    // {
    //     int count=0;
    //     for(char ch: s)
    //     {
    //         if(ch==x)
    //         {
    //             count++;
    //         }
    //     }
        
    //     return count;
    // }
    // int maxScore(string s) {
    //     int max=INT_MIN;
    //     for(int x=0 ; x<s.length()-1;x++)
    //     {
    //         string left=s.substr(0,x+1);
    //         cout<<left<<" ";
    //         string right=s.substr(x+1,s.length()-(x+1));
    //         cout<<right<<endl;
    //         int sum=(countOccurence('0',left)+countOccurence('1',right));
    //         if(sum > max)
    //         {
    //             max=sum;
    //         }
    //     }

    //     return max;
    // }

        int maxScore(string s) {
            int zeroes=0;
            int ones=0;

            //at first we count all the ones in a string 

            for(auto ch : s)
            {
                if(ch=='1')
                {
                    ones++;
                }
            }

            //Now we have 0 number of zeroes and number of ones are stored in oones
            int result=0;
            int max=INT_MIN;

            for(int i=0;i<s.length()-1;i++)
            {
                if(s[i]=='0')
                {
                    zeroes++;
                }
                else 
                {
                    ones--;
                }
                result=zeroes+ones;
                if(result>max)
                {
                    max=result;
                }
            }
            return max;
        }
};