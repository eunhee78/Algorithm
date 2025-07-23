#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    int len = min(A.size(), B.size());
    
    for(int i=0; i<len; i++) {
        answer += A[i] * B[i];
    }

    return answer;
}