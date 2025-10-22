#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상하좌우
int dp[501][501];

int dfs(int x, int y, vector<vector<int>>& tree) {
    if (dp[x][y] != 0) {
        return dp[x][y];
    }

    dp[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];

        if (nx < 0 || nx >= tree.size() || ny < 0 || ny >= tree.size()) continue;
        if (tree[x][y] < tree[nx][ny]) {
            dp[x][y] = max(dp[x][y], dfs(nx, ny, tree) + 1);
        }
    }

    return dp[x][y];
}

int main() {
    int n;
    cin >> n; // 대나무 숲 크기

    vector<vector<int>> tree(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tree[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, dfs(i, j, tree));
        }
    }

    cout << answer << endl;

    return 0;
}