class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad;
        queue<int> dir;
        size_t n=senate.length();

        for(size_t i =0;i<n;i++)
        {
            if(senate[i]=='R')
            {
                rad.push(i);
            }
            else
            {
                dir.push(i);
            }
        }


        while(!rad.empty() && !dir.empty())
        {
            int r=rad.front();
            int d=dir.front();

            if(r<d)//rad bans dir
            {
                rad.push(n);
                n++; //as it goes back to queue with the new index;
            }
            else
            {
                dir.push(n);
                n++;
            }

            rad.pop(); dir.pop();
        }
       
       return !dir.empty()?"Dire":"Radiant";
    }
};