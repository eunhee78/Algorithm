#include <iostream>
#include <vector>
using namespace std;

int R, C;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int alpha[26];
int cnt = 0;

void move_horse(vector<vector<char>> &board, int x, int y, int depth) {
    if(depth > cnt) cnt = depth;
    for(int i=0; i<4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        
        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        
        int idx = board[nx][ny] - 'A';
        
        // 같은 알파벳이 적힌 칸을 두 번 지날 수 없음
        if(!alpha[idx]) {
            alpha[idx] = 1;
            move_horse(board, nx, ny, depth + 1);
            alpha[idx] = 0;
        }
    }
}

int main() {
    cin >> R >> C;
    
    vector<vector<char>> board(R, vector<char>(C));
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> board[i][j];
        }
    }

    alpha[board[0][0] - 'A'] = 1;
    move_horse(board, 0, 0, 1);

    cout << cnt << endl;

    return 0;
}