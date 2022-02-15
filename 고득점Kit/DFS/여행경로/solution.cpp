#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<string>> answerCandidates;

bool cmp(vector<string> a, vector<string> b){
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
} 

void makePath(vector<string> path, vector<vector<string>> tickets){
    if(tickets.size() == 0){
        answerCandidates.push_back(path);
        return;
    }
    
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == path[path.size()-1]){
            vector<string> tempTickets = tickets[i];
            path.push_back(tickets[i][1]);
            tickets.erase(tickets.begin()+i);
            makePath(path, tickets);
            path.erase(path.end());
            tickets.insert(tickets.begin()+i, tempTickets);
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<string> path = {"ICN"};
    makePath(path, tickets);
    
    sort(answerCandidates.begin(), answerCandidates.end(), cmp);
    return answerCandidates[0];
}
