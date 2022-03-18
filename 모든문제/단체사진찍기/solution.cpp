
~
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int count;

int checkAvail(vector<char> lineUp, vector<string> data){
    for(int i=0; i<data.size(); i++){
        char mem1 = data[i][0];
        char mem2 = data[i][2];
        char condition = data[i][3];
        int distanceP = data[i][4] - '0';
        int distanceR = -1;
        int index1 = -1;
        int index2 = -1;
        //cout << mem1 << " " << mem2 << " " << condition << distanceP << endl;
        for(int j=0; j < lineUp.size(); j++){
            
            if(lineUp[j] == mem1 || lineUp[j] == mem2){
                //cout << "?";
                if(index1 > -1){
                    index2 = j;
                    distanceR = index2 - index1 - 1;
                    //cout << index1 << " " << index2 << endl;
                    break;
                } 
                index1 = j;
            }
        }
        if(distanceR != -1){
            if(condition == '>'){
                if(distanceR <= distanceP) return 0;
            }else if(condition == '='){
                if(distanceR != distanceP) return 0;
            }else if(condition == '<'){
                if(distanceR >= distanceP) return 0;
            }
        }
        
    }
    return 1;
    //cout << endl;
}

void dfs(vector<char> members, vector<char> lineUp, vector<string> data){
    if(checkAvail(lineUp, data) == 0){
        return;
    }
    
    if(members.empty()){
        count ++;
        return;
    }
    
    for(int i=0; i<members.size(); i++){
        char temp = members[i];
        lineUp.push_back(temp);
        members.erase(members.begin()+i);
        dfs(members, lineUp, data);
        members.insert(members.begin()+i, temp);
        lineUp.erase(lineUp.end()-1);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    count = 0;
    vector<char> members = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    vector<char> lineUp;
    vector<char> verify = {'N','F','R','A','C','J','M','T'};
    dfs(members, lineUp, data);
    return count;
}
