class Solution {
public:
    bool searchNext(vector<vector<char>>& board, string& word, int row, int col, int index, int m, int n)
    {
        // if index reaches at the end that means we have found the word
        
        if (index == word.length())
            return true;
        
        /* Checking the boundaries if the character at which we are placed is not 
        the required character */
        
        if(row < 0 || col < 0 || row == m || col == n || board[row][col] != word[index] || board[row][col] == '#') 
            return false;
        
        if(word.size() == 1 && board[row][col] == word[index])
            return true;
        
        // this is to prevent reusing of the same character
        
        char c = board[row][col];
        board[row][col] = '#';
        
        bool top = searchNext(board, word, row - 1, col, index + 1, m, n);
        bool down = searchNext(board, word, row + 1, col, index + 1, m, n);
        bool left = searchNext(board, word, row, col + 1, index + 1, m, n);
        bool right = searchNext(board, word, row, col - 1, index + 1, m, n);
        
        board[row][col] = c;  // undo change
        
        return top || down || left || right;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        int index = 0;
        
        // First search the first character
        
        for(int i=0; i<m; i++)
        {
            for(int j =0; j<n; j++)
            {
                if(board[i][j] == word[index])
                {
                    if(searchNext(board, word, i, j, index, m, n))
                    return true;
                }
            }
        }
        return false;
    }
};