#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 접시 수, 초밥 가짓수, 연속 접시 수, 쿠폰 번호 입력 받기
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector <int> dish;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        dish.push_back(num);
    }

    int cnt = 0;
    int result = 0;
    int kind[30001];
    
    // 처음 k개의 초밥 종류 세기
    for (int i=0; i<k; i++) {
        kind[dish[i]]++;
        if(kind[dish[i]] == 1) {
            cnt++;
        }
    }
    
    // 쿠폰 번호 초밥 중복 여부 체크
    if(kind[c] == 0) {
        if(result < cnt + 1) {
            result = cnt + 1;
        }
    }

    if(result < cnt) {
        result = cnt;
    }

    int lt = 1, rt = k;
    while (lt < N) {
        // 제일 앞 초밥 빼기
        kind[dish[lt - 1]] --;
        if(kind[dish[lt - 1]] == 0) {
            cnt--;
        }
        kind[dish[rt]] ++;
        // 새로운 초밥일 경우 개수 늘리기
        if(kind[dish[rt]] == 1) {
            cnt++;
        }
        
        // 쿠폰 번호 초밥 중복 여부 체크
        if(kind[c] == 0) {
            if(result < cnt + 1) {
                result = cnt + 1;
            }
        }
        
        if(result < cnt) {
            result = cnt;
        }

        lt ++;
        rt ++;
        
        if(rt > N - 1) {
            rt = rt % N;
        }
    }

    cout << result << endl;

    return 0;
}