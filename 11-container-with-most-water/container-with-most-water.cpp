class Solution {
public:
  int  maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;

        int max=INT_MIN;
        while(left<right)
        {
            int water=(right-left) * min(height[left],height[right]);
            if(water>max)
            {
                max=water;
            }

            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return max;
    }
};