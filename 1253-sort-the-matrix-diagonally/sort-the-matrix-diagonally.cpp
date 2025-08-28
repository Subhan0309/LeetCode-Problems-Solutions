class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> holder;
        unordered_map<int, int> indices;

        int rows = mat.size();
        int cols = mat[0].size();

        for( int i = 0 ; i < rows ; i++ ){
            for(int j = 0 ; j < cols ; j++ ){
                holder[i-j].push_back(mat[i][j]);
            }
        }
        
        // sort hash values with positive keys in descending order
        // sort hash values with negative keys in ascending  order

        for(auto& [key, vec] : holder){
            sort(vec.begin(), vec.end());
        }

        // make the result matrix using that hash
        vector<vector<int>> result(rows,vector<int>(cols, 0));

        // // 0  ->  [8 , 6 , 1]
        // // 1  ->  [9, 5]
        // // 2  ->  [4]
        // // -1 ->  [2,7]
        // // -2 ->  [3]

        for( int i = 0 ; i < rows ; i++ ){
            for(int j = 0 ; j < cols ; j++ ){
                int dia = i - j;
                int idx = indices[dia];
                result[i][j] = holder[dia][idx];
                indices[dia]++;
            }
        }

        return result;
    }
};