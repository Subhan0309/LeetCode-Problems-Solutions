class Solution {
public:
    // simply loop over the matrix, stored diagnoals in some holder, and sort them 
    // and place them again in the result matrix to return

    // First we need to make holder hash that contains the diagonal values in their values
    
    // 0,0 0,1 0,2
    // 1,0 1,1 1,2
    // 2,0 2,1 2,2

    // 0 -1 -2
    // 1  0 -1
    // 2  1  0  

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        unordered_map<int, vector<int>> holder;
        unordered_map<int, int> indices;

        int n = grid.size();

        for( int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                holder[i-j].push_back(grid[i][j]);
            }
        }
        
        // sort hash values with positive keys in descending order
        // sort hash values with negative keys in ascending  order

        for(auto& [key, vec] : holder){
 
            if(key >= 0) {
                sort(vec.begin(), vec.end(), std::greater<int>());
            } else if(key < 0){
                sort(vec.begin(), vec.end());
            } 

        }

        // make the result matrix using that hash
        vector<vector<int>> result(n,vector<int>(n, 0));

        // // 0  ->  [8 , 6 , 1]
        // // 1  ->  [9, 5]
        // // 2  ->  [4]
        // // -1 ->  [2,7]
        // // -2 ->  [3]

        for( int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < n ; j++ ){
                int dia = i - j;
                int idx = indices[dia];
                result[i][j] = holder[dia][idx];
                indices[dia]++;
            }
        }

        return result;
    }
};