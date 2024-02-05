class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        if(n==0)
        {
            return true;
        }
        if(flowerbed.size()==1 && n==1 && flowerbed[0]==1)
        {
            return false;
        }
        else if(flowerbed.size()==1 && n==1 && flowerbed[0]==0)
        {
            return true;
        }


        
        int lastPotted=-3;

        for(int i=0;i<flowerbed.size();i++)
        {
            if(flowerbed[i]==1)
            {
                lastPotted=i;
                continue;
            }
            else
            {
                //we can pot only by checking whether the next
                // one is empty or previous one is tooo
                if(i==0)
                {
                    //just look forward
                    if(i+1<flowerbed.size() && flowerbed[i+1]==0)
                    {
                        //Flower is potted
                        n--;
                        lastPotted=i;
                    }
                }
                else if(i==flowerbed.size()-1)//jst look behind
                {
                    if(lastPotted+2 <= i)
                    {
                        n--;
                        lastPotted=i;
                    }
                }
                else
                {
                    if(i+1<flowerbed.size() && flowerbed[i+1]==0 && lastPotted+2 <= i)
                    {
                        //Flower is potted
                        n--;
                        lastPotted=i;
                    }
                }

            }
            if(n==0)
            {
                return true;
            }
    

        }

       
       
            return false;
     
    }};