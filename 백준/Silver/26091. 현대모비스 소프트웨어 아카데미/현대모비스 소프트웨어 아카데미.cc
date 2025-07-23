#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector <int> team(N);
    for(int i=0; i<N; i++) {
        cin >> team[i];
    }

    sort(team.begin(), team.end());

    int cnt = 0;
    int lt = 0, rt = N - 1;
    while(lt < rt) {
        if(team[lt] + team[rt] >= M) {
            cnt++;
        }
        lt++;
        rt--;
    }

    cout << cnt;
}