class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end(), [](const int a, const int b) {
            return b < a;  // Reverse the order for descending sorting
        });

        sort(s.begin(), s.end(), [](const int a, const int b) {
            return b < a;  // Reverse the order for descending sorting
        });

        int a =0;
        int b=0;
        int maxChilds=0;

        while(a<g.size() && b < s.size())
        {
            if(g[a]==s[b] || g[a]<s[b])
            {
                maxChilds++;
                a++;
                b++;
            }
            else if(g[a]>s[b])
            {
                a++;
            }

        }

        return maxChilds;
        
    }
};