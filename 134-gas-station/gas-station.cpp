class Solution {
public:
    //Brute Force
//    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
// 	//at start gas tank is empty
// 	int gasNow = 0;
// 	int startIndex = -1;
// 	bool Notcompleted = 0;

// 	for (int i = 0; i < gas.size(); i++)
// 	{
// 		startIndex = i;
// 		int j = i;
// 		int counter = 0;
// 		gasNow = 0;
// 		Notcompleted = 0;

// 		while (counter != gas.size())
// 		{
// 			//I fill my tank with gas at ith station
// 			gasNow = gasNow + gas[j];

// 			if (gasNow >= cost[j])
// 			{
// 				//yes i can travek to the next station
// 				gasNow = gasNow - cost[j];
// 			}
// 			else
// 			{
// 				startIndex = -1;
// 				Notcompleted = 1;
// 				break;
// 			}
// 			j++;
// 			counter++;

// 			if (j > gas.size() - 1)
// 			{
// 				j = 0;
// 			}
// 		}
// 		if (Notcompleted == 0)
// 		{
// 			return startIndex;
// 		}


// 	}

// 	return startIndex;


// }
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sumOfGas=0;
    for(auto g:gas)
    {
        sumOfGas+=g;
    }
     int sumOfcost=0;
    for(auto g:cost)
    {
        sumOfcost += g;
    }

    if(sumOfGas < sumOfcost)
    {
        return -1;
    }

    int start=0;
    int total=0;

    for(int i=0;i<gas.size();i++)
    {
        total += gas[i]-cost[i];

        if(total < 0)
        {
            total=0;
            start=i+1;
        }
    }
    return start;


}
};