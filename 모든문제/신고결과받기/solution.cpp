#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, map<string,int>> reportCollection;
    map<string,int> reportCall;
    
    for(int i=0; i<report.size(); i++){
        istringstream ss(report[i]);
        string reporter;
        string target;
        ss >> reporter >> target;
        reportCollection[target][reporter] = 1;
    }
    
    for(const auto &target: reportCollection){
        if(target.second.size() >= k){
            for(const auto &reporter: target.second){
                reportCall[reporter.first]++;
            }
        }
    }
    
    for(int i=0; i<id_list.size(); i++){
        answer.push_back(reportCall[id_list[i]]);
    }
    return answer;
}
