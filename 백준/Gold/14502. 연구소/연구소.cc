#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int answer = 0;
vector<vector<int>> map, virus_map;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상하좌우

// 안전영역 구하기
void count_area() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (virus_map[i][j] == 0) {
				cnt++;
			}
		}
	}

	answer = max(answer, cnt);
}

// 바이러스 확산시키기
void spread_virus() {
	virus_map = map;
	queue<pair<int, int>> visit;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				visit.push({ i, j });
			}
		}
	}

	while (!visit.empty()) {
		pair<int, int> now = visit.front();
		visit.pop();
		for (int i = 0; i < 4; i++) {
			int nx = now.first + dir[i][0];
			int ny = now.second + dir[i][1];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (virus_map[nx][ny] == 0) {
				virus_map[nx][ny] = 2;
				visit.push({ nx, ny });
			}
		}
	}

	count_area();
}

// 벽 세우기
void set_wall(int cnt) {
	if (cnt == 3) {
		spread_virus();
		return;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					set_wall(cnt + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;

	map.assign(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	set_wall(0);

	cout << answer << endl;

	return 0;
}