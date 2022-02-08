#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> citations) {
    int answer = 1000;
    if(answer > citations.size()){
        answer = citations.size();
    }
    sort(citations.begin(), citations.end(), cmp);
    if(answer > citations[0]){
        answer = citations[0];
    }
    for(int i=answer; i >= 0; i--){
        if(citations[i-1] >= i){
            answer = i;
            break;
        }
    }
    
    return answer;
}
