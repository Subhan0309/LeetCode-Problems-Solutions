class Solution {
public:
    int numberOfBeams(vector<string>& bank) {

        
        vector<int> array;

        int count=0;

        for(int i=0;i<bank.size();i++)
        {
            count=0;
            for(int j=0;j<bank[i].length();j++)
            {
                if(bank[i][j]=='1')
                {
                    count = count + 1;  
                }
            }
            if(count!=0){
                array.push_back(count);
            }
            
        }
        
       if (array.size() == 1 || array.size() == 0)
{
    return 0;
}
        int sum=0;
        for(int i=0; i < array.size() - 1 ; i++)
        {
           sum += array[i]*array[i+1];
        }

        return sum;
    }
};