#include <iostream>
#include <string>
using namespace std;

int result = 0;

void find_distance(string &cmd, int x, int pos) {
	if (x >= cmd.length()) return;
	if (cmd[x] == 'L') {
		pos--;
		if (result < abs(pos)) {
			result = abs(pos);
		}
		find_distance(cmd, x + 1, pos);
	}
	else if (cmd[x] == 'R') {
		pos++;
		if (result < abs(pos)) {
			result = abs(pos);
		}
		find_distance(cmd, x + 1, pos);
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		string cmd;
		cin >> cmd;
		
		result = 0;
		if (cmd.find("?") == string::npos) {
			find_distance(cmd, 0, 0);
		}

		// ? 처리(L, R)
		else {
			string tmp1 = "", tmp2 = "";
			for (int i = 0; i < cmd.length(); i++) {
				if (cmd[i] == '?') {
					tmp1 += "L";
					tmp2 += "R";
				}
				else {
					tmp1 += cmd[i];
					tmp2 += cmd[i];
				}
			}
			find_distance(tmp1, 0, 0);
			find_distance(tmp2, 0, 0);
		}

		cout << result << endl;
	}

	return 0;
}