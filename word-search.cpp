class Solution {
public:
    bool exist(vector<vector<char>>& board, string word, int row, int col, set<pair<int, int>> visited) {
        int rowSize = board.size(); 
        int colSize = board[0].size();
        int wordLen = word.size();
        
        if(wordLen == 0) return false;
        if(row < 0 || row >= rowSize) return false;
        if(col < 0 || col >= colSize) return false;
        
        pair<int, int> p = make_pair(row, col);
        if(visited.find(p) != visited. end()) return false;
        
        if(word[0] != board[row][col]) return false;
        if(wordLen == 1) return true;

        string newWord = word.substr(1);
        visited.insert(p);
        return exist(board, newWord, row+1, col, visited) || exist(board, newWord, row-1, col, visited) ||
            exist(board, newWord, row, col-1, visited) || exist(board, newWord, row, col+1, visited);
    }
    bool exist(vector<vector<char>>& board, string word) {
        int wordLen = word.size();
        if(!wordLen) return false;
        int rowSize = board.size();
        if(rowSize == 0) return false;
        int colSize = board[0].size();
        set<pair<int, int>> visited;
        for(int i = 0; i < rowSize; i++) {
            for(int j = 0; j < colSize; j++) {
                visited.clear();
                if(exist(board, word, i, j, visited))
                    return true;
            }
        }
        return false;
    }
};
