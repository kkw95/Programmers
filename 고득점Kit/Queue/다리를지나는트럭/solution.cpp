#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<vector<int>> onBridge;
    int onBridgeWeight = 0;
    int onBridgeNum = 0;
    
    while(!truck_weights.empty()){
        answer++;
        if(!onBridge.empty()){
            if(answer - onBridge[0][1] == bridge_length){ //Have to unload
                onBridgeWeight -= onBridge[0][0];
                onBridgeNum--;
                onBridge.erase(onBridge.begin());
            }
        }
        
        if(onBridgeWeight + truck_weights.front() <= weight && onBridgeNum+1 <= bridge_length){ //Load possible
            vector<int> temp = {truck_weights.front(), answer};
            onBridgeWeight += temp[0];
            onBridge.push_back(temp);
            //cout << temp[0] << " is loading at " << answer << endl;
            onBridgeNum++;
            truck_weights.erase(truck_weights.begin());
            //cout << onBridgeWeight << endl;

        }
    }
    return answer + bridge_length;
}
