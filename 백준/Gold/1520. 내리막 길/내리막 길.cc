#include <iostream>
#include <vector>
using namespace std;


int M, N;
vector<vector<int>> map, dp;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우
int visit[501][501];
int cnt = 0;

int find_patch(int x, int y) {
    // 도착한 경우
    if(x == M - 1 && y == N - 1) return 1;

    // 이미 방문한 경우
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for(int i=0; i<4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if(map[x][y] > map[nx][ny]) {
            dp[x][y] += find_patch(nx, ny);
        }
    }

    return dp[x][y];
}

int main() {
    cin >> M >> N;

    map = vector<vector<int>>(M, vector<int>(N));
    dp = vector<vector<int>>(M, vector<int>(N, -1));
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
        }
    }

    visit[0][0] = 1;
    cout << find_patch(0, 0);

    return 0;
}