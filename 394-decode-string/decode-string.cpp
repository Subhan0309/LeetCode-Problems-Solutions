class Solution {
public:
   
string decodeString(string s) {
    stack<string> alpha;
    stack<int> digit;

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            string x = "";

            while (isdigit(s[i]))
            {
                x += string(1, s[i]);
                i++;
            }

            digit.push(stoi(x));
            i--;
        }
        else if (isalpha(s[i]) || s[i] == '[')
        {
          
            alpha.push(string(1, s[i]));
        }
        else if (s[i] == ']')//pop values from alpha untill you found the opening bracket
        {
            string holder = "";
            while (alpha.top() != "[")
            {
                holder += alpha.top();
                alpha.pop();
            }
            alpha.pop(); // waste the opening bracket

            reverse(holder.begin(), holder.end());
            int noOfTimes = digit.top();
            digit.pop();

            string result = "";
            while (noOfTimes--)
            {
                result += holder;
            }

            for (int i = 0; i < result.length(); i++)
            {
                alpha.push( string(1,result[i]));
            }


        }
    }

    string res = "";
    while (!alpha.empty())
    {
        res += alpha.top();
        alpha.pop();
    }
    reverse(res.begin(), res.end());

    return res;

}
};