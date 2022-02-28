#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    vector<int> down;
    for(int i=0; i<prices.size()-1; i++){
        if(prices[i] > prices[i+1]){
            down.push_back(i+1);
        }
    }
    
    for(int i=0; i<prices.size(); i++){
        int downPoint = 0;
        if(!down.empty()){
            if(i == down.front()){
                down.erase(down.begin());
            }
        }
        
        for(int j=0; j<down.size(); j++){
            if(prices[i] > prices[down[j]]){
                downPoint = down[j];
                break;
            }
        }
        if(downPoint == 0){
            answer.push_back(prices.size() - i - 1);
        }else{
            answer.push_back(downPoint - i);
        }
    }
    return answer;
}
