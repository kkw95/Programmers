#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    map<int,int> deployDays;
    
    for(int i=0; i<progresses.size(); i++){
        int rest = 100 - progresses[i];
        int day;
        if(rest % speeds[i] == 0){
            day = rest / speeds[i];
        }else{
            day = rest/speeds[i] + 1;
        }
        days.push_back(day);
    }
    int temp = days[0];
    int deployNum = 1;
    for(int i=1; i<days.size(); i++){
        if(temp >= days[i]){
            deployNum++;
        }else{
            answer.push_back(deployNum);
            deployNum = 1;
            temp = days[i];
        }
        
        if(i == days.size()-1){
            answer.push_back(deployNum);
        }
    }
    
    return answer;
}
