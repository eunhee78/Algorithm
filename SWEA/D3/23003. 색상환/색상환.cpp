#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;

	map <string, int> color;
	color.insert({ "blue", 0 });
	color.insert({ "green", 1 });
	color.insert({ "yellow", 2 });
	color.insert({ "orange", 3 });
	color.insert({ "red", 4 });
	color.insert({ "purple", 5 });

	while (T--) {
		string c1, c2;
		cin >> c1 >> c2;

		// 같은 색
		if (color[c1] == color[c2]) {
			cout << "E" << endl;
		}
		// 인접한 색
		else if (abs(color[c1] - color[c2]) == 1 || abs(color[c1] - color[c2]) == 5) {
			cout << "A" << endl;
		}
		// 반대 색
		else if (abs(color[c1] - color[c2]) == 3) {
			cout << "C" << endl;
		}
		else {
			cout << "X" << endl;
		}
	}
	return 0;
}