class Solution {
public:
    string removeStars(string s) {
        stack<int> st;

        for(auto ch:s)
        {
            if(ch=='*')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }


        string result="";
        char holder;

        while(!st.empty())
        { 
            result+=st.top();
            st.pop();
        }

        reverse(result.begin(),result.end());

        return result;

    }
};