class Solution {
public:
   int compress(vector<char>& chars) {

    if (chars.size() == 1)
    {
        return 1;
    }

    string s = "";
    int count = 1;

    for (int i = 0; i < chars.size() - 1; i++)
    {
        if (chars[i] == chars[i + 1]) // checking present to the previous
        {
            count++;
        }
        else
        {
            if (count < 2)
            {
                s += string(1,chars[i]);
            }
            else
            {
                s += string(1, chars[i]);
                s += to_string(count);
            }

            count = 1;

        }
    }
    if (count)
    {
        if (count < 2)
        {
            s += string(1, chars[chars.size()-1]);
        }
        else
        {
            s += string(1, chars[chars.size() - 1]);
            s += to_string(count);
        }
    }


    for (int i = 0; i < s.length(); i++)
    {
        chars[i] = s[i];
    }

    return s.length();
}
};