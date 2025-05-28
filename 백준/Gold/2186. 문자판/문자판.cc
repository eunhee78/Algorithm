#include <iostream>
#include <string>
using namespace std;

int N, M, K;
char board[101][101];
string word;
int dp[101][101][81];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우

int dfs(int x, int y, int idx) {
    if(dp[x][y][idx] != -1) return dp[x][y][idx];
    if(idx == word.length() - 1) return dp[x][y][idx] = 1;

    int cnt = 0;
    for(int i=0; i<4; i++) {
        for(int j=1; j<=K; j++) {
            int nx = x + dir[i][0] * j;
            int ny = y + dir[i][1] * j;
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(board[nx][ny] == word[idx + 1]) {
                cnt += dfs(nx, ny, idx + 1);
            }
        }
    }

    return dp[x][y][idx] = cnt;

}

int main() {
    cin >> N >> M >> K;

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> board[i][j];
        }
    }

    cin >> word;

    // dp 초기화
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            for(int k=0; k<word.length(); k++) {
                dp[i][j][k] = -1;
            }
        }
    }

    int result = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == word[0]) {
                result += dfs(i, j, 0);
            }
        }
    }

    cout << result << endl;

    return 0;
}