class Solution {
public:
    int count(int i, int j, vector<vector<int>>& board) {
        int num = 0;
        int n = board.size();
        int m = board[0].size();
        if (i > 0 && j > 0 && board[i - 1][j - 1] == 1) {
            num++;
        }
        if (i > 0 && board[i - 1][j] == 1) {
            num++;
        }
        if (i > 0 && j < m - 1 && board[i - 1][j + 1] == 1) {
            num++;
        }
        if (j > 0 && board[i][j - 1] == 1) {
            num++;
        }
        if (j < m - 1 && board[i][j + 1] == 1) {
            num++;
        }
        if (i < n - 1 && j > 0 && board[i + 1][j - 1] == 1) {
            num++;
        }
        if (i < n - 1 && board[i + 1][j] == 1) {
            num++;
        }
        if (i < n - 1 && j < m - 1 && board[i + 1][j + 1] == 1) {
            num++;
        }
        return num;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        stack<int> ist;
        stack<int> jst;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int value = count(i, j, board);

                if (board[i][j] == 0 && value == 3) {
                    ist.push (i);
                    jst.push (j);
                }

                else if (board[i][j] == 1 && value < 2) {
                    ist.push (i);
                    jst.push (j);
                }

                else if (board[i][j] == 1 && value > 3) {
                    ist.push (i);
                    jst.push (j);
                }
            }
        }

        while(!ist.empty()){
            if(board[ist.top()][jst.top()]==0){
                board[ist.top()][jst.top()]=1;
                ist.pop();
                jst.pop();
            }
            else if(board[ist.top()][jst.top()]==1){
                board[ist.top()][jst.top()]=0;
                ist.pop();
                jst.pop();
            }
        }
    }
};