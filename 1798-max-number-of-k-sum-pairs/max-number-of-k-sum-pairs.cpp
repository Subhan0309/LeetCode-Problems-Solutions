class Solution {
public:
    // int maxOperations(vector<int>& nums, int k) {
        
    //     vector<bool> visited(nums.size(),0);
    //     // int countVisited=0;

    //     // int ptr1=0;
    //     // int ptr2=nums.size()-1;

    //     int n=nums.size();
    //     int pairs=0;


    //     for(int i=0;i<n;i++)
    //     {
    //         if(visited[i])
    //         {
    //             continue;
    //         }
    //         for(int j=i+1;j<n;j++)
    //         {
    //             if(visited[j])
    //             {
    //                 continue;
    //             }
    //             if(nums[i]+nums[j]==k)
    //             {
    //                 pairs++;
    //                 visited[i]=true;
    //                 visited[j]=true;
    //                 break;
    //             }
               
    //         }
    //     }

    //     return pairs;


    // }

    //   int maxOperations(vector<int>& nums, int k) {
      
    //     sort(nums.begin(),nums.end());

    //     int left=0;
    //     int right=nums.size()-1;
    //     int pairs=0;


    //     while(left<right)
    //     {
    //         if(nums[left]+nums[right] == k)
    //         {
    //             left++;
    //             right--;
    //             pairs++;
    //         }
    //         else if(nums[left]+nums[right] < k)
    //         {
    //             left++;
    //         }

    //         else if(nums[left]+nums[right] > k)
    //         {
    //             right--;
    //         }
    //     }
    //     return pairs;
      
    //   }

    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> my_map;
        int pairs=0;

       
        for(int i=0;i<nums.size();i++)
        {
            int holder=k-nums[i];

            if(my_map[holder])
            {
                my_map[holder]--;
                pairs++;
            }  
            else
            {
                my_map[nums[i]]++;
            }      
        }
        return pairs;


    }




};