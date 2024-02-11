class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {




    stack<int> st;
    int n = temperatures.size();
    vector<int> output(n,0);

    for (int i = 0; i < n; i++)
    {
        int current = temperatures[i];

        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty())
            {
                int comp = st.top();
                if (current > temperatures[comp])
                {
                    output[st.top()] = i - comp;
                    st.pop();
                }
                else
                {
                    break;
                }
            }
            st.push(i);
        }

    }

    return output;
}
};