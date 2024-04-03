class Solution {
public:
    bool solve(string& s,int index, unordered_set<string>& wordDict,vector<int>& DP)
    {
        if(index==s.length())
        {
            return true;
        }
        if(wordDict.find(s) != wordDict.end())
        {
            return true;
        }

        if(DP[index] != -1)
        {
            return DP[index];
        }

        for(int l=1;l<=s.size();l++)
        {
            string temp=s.substr(index,l);

            if((wordDict.find(temp) != wordDict.end()) && solve(s,index+l,wordDict,DP) )
            {
                return DP[index]=1;
            }
        }

        return DP[index]=0;



    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mySet;

        for(string a:wordDict)
        {
            mySet.insert(a);
        }

        vector<int> DP(s.length(),-1);
        return solve(s,0,mySet,DP);
    }
};