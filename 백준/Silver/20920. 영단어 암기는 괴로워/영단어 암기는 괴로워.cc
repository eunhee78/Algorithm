#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;

map <string, int> cnt;

bool compare(string a, string b) {
    // 1. 빈도수 비교
    if(cnt[a] != cnt[b]) return cnt[a] > cnt[b];
    else {
        // 2. 길이 비교
        if(a.length() != b.length()) {
            return a.length() > b.length();
        }
        // 3. 알파벳 비교
        return a < b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    vector <string> list;

    for(int i=0; i<N; i++) {
        string word;
        cin >> word;
        // M 이상일 경우만 저장
        if(word.length() >= M) {
            if(cnt.find(word) == cnt.end()) {
                list.push_back(word);
                cnt[word] = 1;
            }
            else {
                cnt[word]++;
            }
        }
    }

    sort(list.begin(), list.end(), compare);

    for(int i=0; i<list.size(); i++) {
        cout << list[i] << "\n";
    }

    return 0;
}