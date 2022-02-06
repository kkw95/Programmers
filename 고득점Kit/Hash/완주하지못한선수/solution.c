#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i;
    sort(participant.begin(), participant.end());
    
    sort(completion.begin(), completion.end());
    
    for(i=0; i<completion.size(); i++){
        if(completion[i] != participant[i]){
            return participant[i];
        }
    }
    return participant[i];
}
