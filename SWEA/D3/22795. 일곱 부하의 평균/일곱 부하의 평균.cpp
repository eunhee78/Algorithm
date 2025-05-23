#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;
	
	while (T--) {
		int sum = 0, max = 0;
		for (int i = 0; i < 6; i++) {
			int height;
			cin >> height;
			sum += height;
			if (max < height) {
				max = height;
			}
		}

		int result = max + 1;
		while ((result + sum) % 7 != 0) {
			result++;
		}

		cout << result << endl;
	}

	return 0;
}