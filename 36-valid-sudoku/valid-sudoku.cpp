class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows[9], cols[9], boxes[9];

        for(int i = 0; i < board.size() ; i++ ){
            for(int j = 0; j < board.size() ; j++ ){

                char ch = board[i][j];
                if (ch == '.'){
                    continue;
                }

                int boxIdx = (i / 3) * 3 + (j / 3);

                if(rows[i].count(ch) || cols[j].count(ch) || boxes[boxIdx].count(ch)){
                    return false;
                }

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[boxIdx].insert(ch);

            }
        }

        return true;
    }
};