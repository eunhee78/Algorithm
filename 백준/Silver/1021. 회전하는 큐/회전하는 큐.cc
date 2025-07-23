#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for(int i=1; i<=N; i++) {
        dq.push_back(i);
    }

    int cnt = 0;
    for(int i=0; i<M; i++) {
        int x, idx;
        cin >> x;

        for(int i=0; i<dq.size(); i++) {
            if(dq[i] == x) {
                idx = i;
            }
        }

        while(dq.front() != x) {
            // 왼쪽으로 돌리기
            if(dq.size() - idx <= dq.size() / 2) {
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
            // 오른쪽으로 돌리기
            else {
                int tmp = dq.front();
                dq.pop_front();
                dq.push_back(tmp);
            }
            cnt++;
        }
        dq.pop_front();
    }

    cout << cnt;

    return 0;
}