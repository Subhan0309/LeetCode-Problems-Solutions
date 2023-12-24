class Solution {



public:
  
    int minOperations(string s) {
    int count_to_swap_1 = 0;
    string t = s;

    for (int i = 0; i < s.length(); i+=2)
    {
        if (s[i] == '1')
        {
            if (i+1 < s.length() && s[i + 1] != '0')
            {
                s[i+1] = '0';
                count_to_swap_1++;
            }
        }
        else if (s[i] != '1')
        {
            s[i] = '1';
            count_to_swap_1++;
            if (i + 1 < s.length() && s[i + 1] != '0')
            {
                s[i+1] = '0';
                count_to_swap_1++;
            }

            
        }
    }
    cout << s << " " << endl;


    int count_to_swap_o = 0;
    for (int i = 0; i < t.length(); i += 2)
    {
        if (t[i] == '0')
        {
            if (i + 1 < t.length() && t[i + 1] != '1')
            {
                t[i + 1] = '1';
                count_to_swap_o++;
            }
        }
        else if (t[i] != '0')
        {
            t[i] = '0';
            count_to_swap_o++;
            if (i + 1 < t.length() && t[i + 1] != '1')
            {
                t[i + 1] = '1';
                count_to_swap_o++;
            }


        }
    }
    cout << t << " " << count_to_swap_o<<endl;

    return count_to_swap_1> count_to_swap_o? count_to_swap_o: count_to_swap_1;
}
};
