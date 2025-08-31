class Solution {
public:
    bool isValid(vector<vector<char>>& board, int rowIdx, int colIdx, char digit){
        // First we will iterate over the row and col of the board
        for(int i = 0 ; i < 9 ; i++){
            
            if(board[rowIdx][i] == digit || board[i][colIdx] == digit){
                return false;
            }
            
        }

        // Now we will check for the validity of the box

        int startRowIdx = rowIdx / 3 * 3;
        int startColIdx = colIdx / 3 * 3;
        int endRowIdx   = startRowIdx + 3;
        int endColIdx   = startColIdx + 3;

        for( int i = startRowIdx ; i < endRowIdx ; i++ ){
            for( int j = startColIdx ; j < endColIdx ; j++ ){
                if ( board[i][j] == digit )
                {
                    return false;
                }
            }
        }

        return true;
    }

    bool solveMySoduku(vector<vector<char>>& board){
        for( int i = 0 ; i < 9 ; i++ ){
            for( int j = 0 ; j < 9 ; j++ ){

                if (board[i][j] != '.'){
                    continue;
                }
                
                for( char digit = '1' ; digit <= '9' ; digit++){
                    
                    if(isValid(board, i, j, digit)){
                        
                       board[i][j] = digit;
                        
                        if (solveMySoduku(board)){
                            return true;
                        }
                        
                        board[i][j] = '.'; 
                    }
                }

                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {

        solveMySoduku(board);
        
        
    }
};