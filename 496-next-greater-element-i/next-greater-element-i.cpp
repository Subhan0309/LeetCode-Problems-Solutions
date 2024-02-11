class Solution {
public:
   vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    vector<int> nextGreator(nums2.size(),-1);

    unordered_map<int, int> key_index;

    for (int i = 0; i < nums2.size(); i++)
    {
        key_index[nums2[i]] = i;

        int curr = nums2[i];

        if (st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty())
            {
                int comp = st.top();

                if (curr > nums2[comp])
                {
                    nextGreator[comp] = curr;
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


    vector<int> answer;

    for (int i = 0; i < nums1.size(); i++)
    {
        int index = key_index[nums1[i]];
        answer.push_back(nextGreator[index]);
    }
    return answer;
}
};