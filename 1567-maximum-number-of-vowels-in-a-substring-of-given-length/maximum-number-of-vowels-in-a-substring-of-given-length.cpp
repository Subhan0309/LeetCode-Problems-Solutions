class Solution {
public:
    int maxVowels(string s, int k) {
        
        int max=-1;



        string holder="";

        int left=0;
        int right=k-1;
        
        int count=0;
        for(int i=0;i<=right;i++)
        {
            char ch=s[i];

            if(ch == 'a' || ch=='e' || ch=='i'  || ch=='o' || ch=='u' )
            {
                ++count;
            }
        }

        if(count>max)
        {
            max=count;
        }

       


        while(right<s.length())
        {     
            char ch=s[left];                

            if(ch == 'a' || ch=='e' || ch=='i'  || ch=='o' || ch=='u' )
            {
                --count;
            }

            
            left++;
            right++;

             ch=s[right];                

            if(ch == 'a' || ch=='e' || ch=='i'  || ch=='o' || ch=='u' )
            {
                ++count;
            }
            if(count>max)
            {
                max=count;
            }
        }

    return max;
    }

};