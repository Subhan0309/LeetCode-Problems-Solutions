class Solution {
public:
  
	vector<vector<int>> transpose(vector<vector<int>> matrix)
{
	if (matrix.size() == 1 && matrix[0].size() == 1)
	{
		return matrix;
	}
	int size = 0;
	if (matrix.size() < matrix[0].size())
	{
		size = matrix.size();
	}
	else
	{
		size = matrix[0].size();
	}

	int i = 0;
	int j = 0;

	for (; i <size; i++)
	{
		for (j = i; j < size; j++)
		{
			if (i != j) {
				int temp = matrix[j][i];
				matrix[j][i] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}
	}

	if (i < matrix.size()  && j >= matrix[0].size() -1 )
	{
		j = 0;
		int copyOfi = i;
		//int copyOfj = j;
		/*  
			1 2
			3 4
			5 6
			7 8 
		*/
		int szie = matrix[i].size();

		for (j = 0; j < szie ; j++)
		{
			for (i=copyOfi; i < matrix.size(); i++)
			{			
				matrix[j].push_back(matrix[i][j]);
			}
		}

		int size_Uppper = matrix.size();
		int size = matrix[copyOfi].size();

		//
		//for (int x = size_Uppper - 1; x >= copyOfi ;x--)
		//{
		//	for (int y = size - 1; y >= 0; y--)
		//	{
		//		auto it = std::find(matrix[x].begin(), matrix[x].end(), matrix[x][y]);

		//		if (it != matrix[x].end()) {
		//			matrix[x].erase(it);
		//		}
		//	}
		//}
		for (int x = matrix.size()-1; x >= copyOfi; x--)
		{
			matrix.erase(matrix.begin() + x);

		}
	}
	else if (j < matrix[0].size() && i >= matrix.size() - 1 )
	{
		/*1 4 3 
		  2 5 6 */
		vector<int> holder;
		i = 0;
		int copyOfi = i;
		int copyOfj = j;
		int size = matrix.size();

		for (j = copyOfj; j < matrix[0].size(); j++)
		{
			for (int y = 0; y < size; y++)
			{
				holder.push_back(matrix[y][j]);
			}
			matrix.push_back(holder);
			holder.clear();
		}

		for (int y = i; y < size; y++)
		{
			for (int x = matrix[y].size()-1 ; x>= copyOfj ; x--)
			{	
				matrix[y][x] = INT_MIN;
				auto it = std::find(matrix[y].begin(), matrix[y].end(), INT_MIN);
				if (it != matrix[y].end()) {
					matrix[y].erase(it);
				}
			}
		}	

	}
	for (int i = 0; i < matrix.size(); i++)
	{	
		for (int j = 0; j < matrix[0].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
				cout << endl;

	}



	return matrix;


}

};