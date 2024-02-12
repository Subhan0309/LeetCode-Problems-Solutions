class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start=0;
        int end=letters.size()-1;

        char holder='0';

        while(start<=end)
        {
            int mid=(start+end)/2 ;

            if(letters[mid] > target)
            {
                holder=letters[mid];
                end=mid-1;
            }
            else 
            {
                start=mid+1;
            }
        }

        if(holder!='0')
        {
            return holder;
        }
        else
        {
            return letters[0];
        }


    }
};