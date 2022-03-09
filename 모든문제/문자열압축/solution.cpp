#include <string>
#include <vector>
#include <iostream>

using namespace std;
int shortest = 10000;

void findSequential(string target, int count, vector<string> parse, int index, string answer){
    if(index == parse.size()-1){
        if(parse[index] == target){
            count++;
            answer += to_string(count) + target;
        }else{
            if(count == 1){
                answer += target;
            }else{
                answer += to_string(count) + target;
            }
            answer += parse[index];
        }
        if(shortest > answer.size()) shortest = answer.size();
        //cout << answer << endl;
        return;
    }
    
    if(parse[index] == target){
        count++;
        findSequential(parse[index], count, parse, index+1, answer);
    }else{
        if(count == 1){
            answer += target;
        }else{
            answer += to_string(count) + target;
        }
        findSequential(parse[index], 1, parse, index+1, answer);
    }
}

int solution(string s) {
    int answer = 0;
    if(s.size() == 1) return 1;

