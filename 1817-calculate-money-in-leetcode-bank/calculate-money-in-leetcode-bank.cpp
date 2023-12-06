class Solution {
public:
   int totalMoney(int n) {
	if (n <= 7)
	{
		return n * (n + 1) / 2;
	}

	int mod = n % 7;
	int div = n / 7;

	int i = 0;
	int ans = 0;
	int updatedN = 7;

	while (i < div)
	{
		ans += (updatedN * (updatedN + 1) ) / 2 - (updatedN - 7) *(updatedN - 7+1)/2;
		updatedN++;
		i++;
	}

	if (mod != 0)
	{
		for (int i = 0; i < mod; i++)
		{
			ans += (i + div + 1);
		}
	}
	else
	{
		return ans;
	}
	return ans;
}
};