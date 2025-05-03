#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        string p, arr;
        cin >> p >> n >> arr;
        
        deque <string> result;
        if(n > 0) {
            string temp = "";
            for(int i=1; i<arr.length(); i++) {
                if(arr[i] == ',' || arr[i] == ']') {
                    result.push_back(temp);
                    temp = "";
                }
                else {
                    temp += arr[i];
                }
            }
        }
        
        int flag = 0, err = 0;
        for(int i=0; i<p.length(); i++) {
            if(err) break;
            if(p[i] == 'R') {
                flag++;
            }
            else {
                if(result.empty()) {
                    if(err == 0) {
                        err = 1;
                        cout << "error" << endl;
                    }
                }
                else {
                    if(flag % 2 == 0) {
                        result.pop_front();
                    }
                    else {
                        result.pop_back();
                    }
                }
            }
        }

        if(!err) {
            cout << "[";
            if(flag % 2 != 0) reverse(result.begin(), result.end());
            for(int i=0; i<result.size(); i++) {
               cout << result[i];
               if(i != result.size() - 1) cout << ",";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}