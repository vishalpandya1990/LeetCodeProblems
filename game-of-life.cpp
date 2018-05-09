class Solution {
public:
    int magicNumber = -1;
    int rowSize = -1, colSize = -1;
    int getCountOfLiveNeighbors(vector<vector<int>>& board, int row, int col) {
        //cout << "getCount row = " << row << " col = " << col << " val = " << board[row][col] << std::endl;
        return board[row][col] / magicNumber;
    }
    void encodeCountOfLiveNeighbors(vector<vector<int>>& board, int row, int col) {
        //cout << "encodeCount row = " << row << " col = " << col << " val = " << board[row][col] << std::endl;
        int count = 0;
        if(isAlive(board, row-1, col)) count++;
        if(isAlive(board, row-1, col-1)) count++;
        if(isAlive(board, row-1, col+1)) count++;
        if(isAlive(board, row+1, col)) count++;
        if(isAlive(board, row+1, col-1)) count++;
        if(isAlive(board, row+1, col+1)) count++;
        if(isAlive(board, row, col-1)) count++;
        if(isAlive(board, row, col+1)) count++;
        bool isLive = isAlive(board, row, col);
        int finalValue = count*magicNumber;
        if(isLive)
            finalValue++;
        //cout << "encodeCount row = " << row << " col = " << col << " finalVal = " << finalValue << std::endl;
        board[row][col] = finalValue;
    }
    bool isAlive(vector<vector<int>>& board, int row, int col) {
        if(row < 0 || row >= rowSize) return false;
        if(col < 0 || col >= colSize) return false;
        //cout << "row = " << row << " col = " << col << " val = " << board[row][col] << std::endl;
        int remainder = board[row][col] % magicNumber;
        //cout << "isAlive ? " << remainder << std::endl;
        return remainder == 1 ? true : false;
    }
    void updateState(vector<vector<int>>& board, int row, int col, bool alive) {
        //cout << "Update State row = " << row << " col = " << col << " val = " << alive << std::endl;
        if(alive)
            board[row][col] = 1;
        else
            board[row][col] = 0;
    }
    void gameOfLife(vector<vector<int>>& board) {
        rowSize = board.size();
        colSize = board[0].size();
        magicNumber = rowSize * colSize + 1;
        for(int i = 0; i < rowSize; i++) {
            for(int j = 0; j < colSize; j++) {
                encodeCountOfLiveNeighbors(board, i, j);
            }
        }
        //cout << "encode done\n";
        for(int i = 0; i < rowSize; i++) { // for1
            for(int j = 0; j < colSize; j++) { // for2
                int count = getCountOfLiveNeighbors(board, i, j);
                bool isLive = isAlive(board, i, j);
                //cout << "about to update state - row = " << i << " col = " << j << std::endl;
                if(isLive) {
                    if(count == 2 || count == 3) {
                        updateState(board, i, j, true);
                    } else {
                        updateState(board, i, j, false);
                    }
                } else {
                    if(count == 3) {
                        updateState(board, i, j, true);
                    } else {
                        updateState(board, i, j, false);
                    }
                }
            } // for2 ends
        } // for1 ends
        
        
    }
};
