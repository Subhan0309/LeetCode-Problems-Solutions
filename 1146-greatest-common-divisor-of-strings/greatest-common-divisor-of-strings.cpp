class Solution {
public:
int GCD(int n1, int n2)
{
    // i am assuming that n2 contains the smaller number all the times
    if (n2 > n1)
    {
        n1 = (n2 + n1);
        n2 = n1 - n2;
        n1 = n1 - n2;
    }
    int gcd = 0;
    for (int i = 1; i <= n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }
    return gcd;
}
string gcdOfStrings(string str1, string str2) {
    int l1 = str1.length();
    int l2 = str2.length();

    int sizeOfGcd = GCD(l1, l2);

    //pick that size of substring from the original string and start appending it.

    string subst = str1.substr(0, sizeOfGcd);

    int noOftimes1 = l1 / sizeOfGcd;
    int noOftimes2 = l2 / sizeOfGcd;

    //First check for the str1 and then for the str2
    string result = "";
    while (noOftimes1--)
    {
        result += subst;
    }

    if (result != str1)
    {
        return "";
    }
    result = "";
    while (noOftimes2--)
    {
        result += subst;
    }
    if (result != str2)
    {
        return "";
    }

    return subst;



}
};