#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;

    stack <int> list;

    for(int i=0; i<N; i++) {
        int cmd;
        cin >> cmd;
        if(cmd == 1) {
            int num;
            cin >> num;
            list.push(num);
        }
        else if(cmd == 2) {
            if(list.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << list.top() << "\n";
                list.pop();
            }
        }
        else if(cmd == 3) {
            cout << list.size() << "\n";
        }
        else if(cmd == 4) {
            cout << list.empty() << "\n";
        }
        else {
            if(list.empty()) {
                cout << -1 << "\n";
            }
            else {
                cout << list.top() << "\n";
            }
        }
    }

}