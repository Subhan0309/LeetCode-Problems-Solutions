class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int indexToBesearched=-1;

        if(ruleKey=="type")
        {
            indexToBesearched=0;
        }
        else if(ruleKey=="color")
        {
            indexToBesearched=1;
        }
        else if(ruleKey=="name")
        {
            indexToBesearched=2;
        }

        int count=0;
        for(int i=0 ; i<items.size();i++)
        {
            if(items[i][indexToBesearched]==ruleValue)
            {
                count++;
            }
        }

        return count;
    }
};