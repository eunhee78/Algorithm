#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector <int> temperature(N);
    for(int i=0; i<N; i++) {
        cin >> temperature[i];
    }

    int lt = 0, result = -10000000;
    while(lt <= N - K) {
        int sum = 0;
        for(int idx = lt; idx < lt + K; idx++) {
            if(idx >= N) break;
            sum += temperature[idx];
        }

        if(sum > result) result = sum;

        lt++;
    }

    cout << result;

    return 0;
}