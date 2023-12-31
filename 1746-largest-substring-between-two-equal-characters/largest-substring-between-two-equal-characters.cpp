class Solution {
public:
    int maxLengthBetweenEqualCharacters(string str) {
      
    vector<vector<int>> count(26, vector<int>(2, -1));

    for (int i = 0; i < str.length(); i++)
    {
        int x = str[i] - 97;

        if (count[x][0]!=-1) // means that the character come again
        {
            count[x][1] = i;
        }
        else // the character is occuring first time , so i stored its first index
        {
            count[x][0] = i;
        }
    }
    int max = -1;
    for (int i = 0; i < count.size(); i++)
    {
        int y = count[i][1] - count[i][0];
        if (y > max)
        {
            max = y;
        }
    }

    return max-1;


    }
};