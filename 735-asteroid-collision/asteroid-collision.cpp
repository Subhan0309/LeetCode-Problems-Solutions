class Solution {
public:
   
vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    int n = asteroids.size();
    int current = 0;

    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] >= 0)
        {
            st.push(asteroids[i]);
        }
        else
        {
            current = asteroids[i];//asteroid moving leftwards
            bool noPush = false;

            while (!st.empty())
            {
                int rightMov = st.top();
                 if (rightMov < 0)
                    {
                        break;
                    }

                if (rightMov == abs(current))//same weight both destroyed
                {
                    st.pop();
                    noPush = true;
                    break;
                }
                else if (rightMov > abs(current))//top is greator so left destroyed
                {
                    noPush = true;
                    break;
                }
                else//left keeps on destroying untill it find bigger man
                {
                    st.pop();
                }
            }
            if(!noPush)
                st.push(current);
        }
    }



    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}
};