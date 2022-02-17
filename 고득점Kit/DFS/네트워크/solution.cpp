#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;
int networkNum;
map<int,int> usedNetwork;

void makeNetwork(vector<vector<int>> computers, int current){
    
    for(int i=0; i<computers[current].size(); i++){
        if(computers[current][i] == 1){
            if(usedNetwork[i] == 0){
                usedNetwork[i] = 1;
                makeNetwork(computers, i);
            }
        }
    }
    
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    networkNum = 0;
    
    for(int i=0; i<n; i++){
        if(usedNetwork[i] == 0){
            makeNetwork(computers, i);
            networkNum++;

        }
    }
    return networkNum;
}
