#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        int dx = x1 - x2;
        int dy = y1 - y2;
        int dist = pow(dx, 2) + pow(dy, 2);

        int diff = pow(r1 - r2, 2);
        int sum = pow(r1 + r2, 2);

        if(dist == 0) {
            // 같은 원일 경우
            if(r1 == r2) {
                cout << "-1" << endl;
            }
            // 중심이 같고 반지름은 다름
            else {
                cout << "0" << endl;
            }
        }
        // 한 점에서 만나는 경우
        else if(diff == dist || sum == dist) {
            cout << "1" << endl;
        }
        // 두 점에서 만나는 경우
        else if(diff < dist && dist < sum) {
            cout << "2" << endl;
        }
        // 만나지 않는 경우
        else {
            cout << "0" << endl;
        }
    }
    return 0;
}