#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		vector <char> result(51);
		vector <int> player1, player2;
		for (int i = 0; i < N * 2; i++) {
			int num;
			cin >> num;
			if (i < N) {
				player1.push_back(num);
			}
			else {
				player2.push_back(num);
			}
		}

		int cnt = 0, ap = 0, bp = 0;
		while (cnt < N) {
			// A 팀
			if (cnt % 2 == 0) {
				while (1) {
					if (result[player1[ap]] == 'B') {
						ap++;
						if (ap == N) break;
					}
					else {
						result[player1[ap++]] = 'A';
						cnt++;
						break;
					}
				}
			}

			// B 팀
			else {
				while (1) {
					if (result[player2[bp]] == 'A') {
						bp++;
						if (bp == N) break;
					}
					else {
						result[player2[bp++]] = 'B';
						cnt++;
						break;
					}
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			cout << result[i];
		}
        cout << endl;
	}
	return 0;
}