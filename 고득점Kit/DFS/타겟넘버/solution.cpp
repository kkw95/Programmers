#include <string>
#include <vector>
#include <iostream>

using namespace std;
int count;

void makeCombi(int iter, int value, vector<int> numbers, int target, int max){
    if(iter == max){
        if(value == target){
            count++;
        }
        return;
    }
    
    makeCombi(iter+1, value+numbers[iter], numbers, target, max);
    makeCombi(iter+1, value-numbers[iter], numbers, target, max);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    count = 0;
    
    makeCombi(0, 0, numbers, target, numbers.size());
    return count;
}
