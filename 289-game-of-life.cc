#include <stdio.h>
#include <vector>

using namespace std;

inline int
count_live(vector<vector<int> > &board, int row, int col,
        int i, int j) {
    int cnt = 0;
    int m,n;
    for (m = -1; m < 2; m++) {
        for (n = -1; n < 2; n++) {
            if (i+m < 0 || i+m >= row || j+n < 0 || j+n >= col || (m == 0 && n == 0)) {
                continue;
            }
            cnt += board[i+m][j+n];
        }
    }
    return cnt;
}

void gameOfLife(vector<vector<int> >& board) {
    vector<int> vec;
    int i,j, row, col, live_cnt;
    row = board.size();
    col = board[0].size();
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            live_cnt = count_live(board, row, col, i, j);
            if (1 == board[i][j] && (live_cnt < 2 || live_cnt > 3)) {
                vec.push_back((i << 8) | j);
            } if (0 == board[i][j] && 3 == live_cnt) {
                vec.push_back((i << 8) | j);
            }
        }
    }
    int size = vec.size();
    for (int k = 0; k < size; k++) {
        i = vec[k] >> 8;
        j = vec[k] & 0XFF;
        board[i][j] = 1 - board[i][j];
    }
}

int
main(void) {
    return 0;
}
