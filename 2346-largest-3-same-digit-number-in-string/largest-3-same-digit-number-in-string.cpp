class Solution {
public:
 bool checkGood_String(string str) {
    if (str.length() != 3) {
        return false;
    }

    if ((str[0] == str[1]) && (str[1] == str[2])) {
        return true;
    }

    return false;
}
bool isGreator(string str1,string str2)
{
    return stoi(str1)>stoi(str2);
}

string largestGoodInteger(string num) {
    string max = "-111";

    int left = 0;
    int right = 2;

    while (right < num.size()) {

        string holder = num.substr(left, right - left + 1);

        if (checkGood_String(holder)) {
           
            if (isGreator(holder,max)) {
                max = holder;
            }
        }
        left ++;
        right++;
    }

    return (max == "-111") ? "" : (max);
}
};