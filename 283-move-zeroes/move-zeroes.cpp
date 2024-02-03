class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int length = nums.size();
    int left = 0;

    for (int i = 0; i < length; i++){
        
        if (nums[i] != 0)
        {
            int temp = nums[left];
            nums[left] = nums[i];
            nums[i] = temp;

            left++;
        }
        
    }
    
    


    for (int i = 0; i < length; i++)
    {
        cout << nums[i] << " ";
    }

}
};