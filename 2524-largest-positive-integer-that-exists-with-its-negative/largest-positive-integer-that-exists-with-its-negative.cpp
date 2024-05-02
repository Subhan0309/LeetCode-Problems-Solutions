class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int p1=0;
        int p2=nums.size()-1;
        int max=INT_MIN;

        while(p1<p2)
        {
           int h1=abs(nums[p1]);
           int h2=abs(nums[p2]);

            if( h1==h2 && (nums[p1]<0 && nums[p2]>0) )
            {
                if(h1>max)
                {
                    max=h1;
                }
               p1++;
               p2--;
            }
            else if(h1<h2)
            {
                p2--;
            }
            else
            {
                p1++;
            }
        }

        return max==INT_MIN? -1 : max;

    }
};