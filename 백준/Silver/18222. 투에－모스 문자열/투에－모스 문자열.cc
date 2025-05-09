#include <iostream>
#include <string>
using namespace std;

int main() {
    long long k;
    cin >> k;

    long long x = k - 1;
    int cnt = 0;

    while(x > 0) {
        cnt += x & 1;
        x >>= 1;
    }

    cout << cnt % 2;

    return 0;
}