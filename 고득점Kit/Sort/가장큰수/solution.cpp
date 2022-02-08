#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    string aFirst = a + b;
    string bFirst = b + a;
    
    return aFirst > bFirst;
}

string solution(vector<int> numbers) {
    vector<string> numbersToString;
    
    for(int i=0; i<numbers.size(); i++){
        numbersToString.push_back(to_string(numbers[i]));
    }
    sort(numbersToString.begin(), numbersToString.end(), cmp);
    string answer = "";
    for(string number : numbersToString){
        answer += number;
    }
    
    if(answer[0] == '0'){
        answer.clear();
        answer.push_back('0');
    }
    return answer;
}
