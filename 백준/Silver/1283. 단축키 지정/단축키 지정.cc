#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    cin.ignore();

    map <char, int> list;

    for(int i=0; i<N; i++) {
        string option;
        getline(cin, option);
        
        int idx = 0;
        int check = 0;
        while(!check) {
            if(list.find(tolower(option[idx])) == list.end()) {
                list.insert(make_pair(tolower(option[idx]), 1));
                option.insert(idx, "[");
                option.insert(idx + 2, "]");
                check = 1;
            }
            // 다음 단어 위치 찾기
            idx = option.find(" ", idx);
            if(idx == string::npos) break;
            idx++;
        }

        if(!check) {
            for(int j=0; j<option.length(); j++) {
                if(option[j] == ' ') continue;
                if(list.find(tolower(option[j])) == list.end()) {
                    list.insert(make_pair(tolower(option[j]), 1));
                    option.insert(j, "[");
                    option.insert(j + 2, "]");
                    break;
                }
            }
        }

        cout << option << "\n";

    }
    return 0;
}
