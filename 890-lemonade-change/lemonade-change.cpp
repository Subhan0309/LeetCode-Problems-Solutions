class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int bill_five=0;
        int bill_ten=0;
        int bill_twenty=0;

        int holder=0;

        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                bill_five++;
            }
            else if(bills[i]==10)
            {
                if(bill_five)
                {
                    bill_five--;
                    bill_ten++;
                }
                else
                {
                    return false;
                }
            }
            else if(bills[i]==20)
            {
                if(bill_ten)
                {
                    bill_ten--;
                    if(bill_five)
                    {
                        bill_five--;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(bill_five>=3)
                {
                    bill_five-=3;
                }
                else
                {
                    return false;
                }
            }

        }
        return true;
    }
};