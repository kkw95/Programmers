#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
bool cmp(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] > b[0];
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    vector<vector<int>> priority;
    
    for(int i=0; i<priorities.size(); i++){
        vector<int> temp = {priorities[i], i};
        priority.push_back(temp);
    }
    //sort(priority.begin(), priority.end(), cmp);
    
    while(!priority.empty()){
        bool urgent = false;
        vector<int> temp = priority.front();
        priority.erase(priority.begin()); //Pop first element
        for(int i=0; i<priority.size(); i++){
            if(priority[i][0] > temp[0]){ //if there is urgent task
                priority.push_back(temp); //Push the element
                urgent = true;            //notify urgent
                break;
            }
        }
        
        if(!urgent){ //if the element can be print now
            answer++;
            if(temp[1] == location){
                return answer;
            } //if the element was target return answer
        }
    }
    return answer+1;
}
