class Solution {
public:
bool CheckOdd(int num)
{
	return (num % 2 != 0);
}
 string largestOddNumber(string num) {
	//visit all the string
	string result = "";
	string holder = "";

	for (int i = num.length()-1; i >= 0; i--)
	{
		

		if (CheckOdd(int(num[i]) - int('0')))
		{
			result += num.substr(0, i+1);
			break;
		}

	}

	return result;
}
};