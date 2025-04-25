#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 전체 용액 수 입력 받기
    int N;
    cin >> N;

    vector <int> arr(N);
    // 특성값 입력 받기
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    // 알칼리성 + 산성 값이 가까운 용액을 만들어내는 두 용액 찾기
    int lt = 0, rt = N - 1;
    int result = 2000000001, idx[2];
    
    while(lt < rt) {
        if (result > abs(arr[lt] + arr[rt])) {
            result = abs(arr[lt] + arr[rt]);
            idx[0] = lt;
            idx[1] = rt;
        }
        if (arr[lt] + arr[rt] > 0) {
            rt--;
        }
        else {
            lt++;
        }
    }

    cout << arr[idx[0]] << " " << arr[idx[1]] << endl;

    return 0;
}