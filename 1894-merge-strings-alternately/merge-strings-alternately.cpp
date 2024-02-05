class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int ptr1=0;
        int ptr2=0;

        string result="";

        while(ptr1<word1.length() && ptr2<word2.length())
        {
            result+=word1[ptr1];
            result+=word2[ptr2];
            ptr1++;
            ptr2++;

        }

        while(ptr1<word1.length())
        {
            result+=word1[ptr1];
            ptr1++;
        }
        while(ptr2<word2.length())
        {
            result+=word2[ptr2];
            ptr2++;
        }

        return result;
    }
};