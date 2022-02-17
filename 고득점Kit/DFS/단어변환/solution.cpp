#include <string>
#include <vector>
#include <iostream>

using namespace std;
int shortNum;

void makeShortPath(string target, string current, int num, vector<string> words){
    if(current == target){
        if(num < shortNum){
            cout << num << endl;
            for(int i=0; i<words.size(); i++){
                cout << words[i] << " ";
            }
            cout << endl;
            shortNum = num;
        }
        return;
    }
    int differentCount = 0;
    
    for(int i=0; i<words.size(); i++){
        differentCount = 0;
        for(int j=0; j<current.size(); j++){
            if(current[j] != words[i][j]){
                differentCount++;
            }
            if(differentCount > 1){
                differentCount = 0;
                break;
            }
        }
        if(differentCount == 1){
            string temp = words[i];
            words.erase(words.begin()+i);
            makeShortPath(target, temp, num+1, words);
            words.insert(words.begin()+i, temp);
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    shortNum = 100;
    words.insert(words.begin(), begin);
    makeShortPath(target, words[0], 0, words);
    
    if(shortNum == 100) return 0;
    return shortNum;
}
